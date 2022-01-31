#include <Arduino.h>
#if defined(ESP32)
  #include <WiFi.h>
#elif defined(ESP8266)
  #include <ESP8266WiFi.h>
#endif
#include <Firebase_ESP_Client.h>

#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

#define WIFI_SSID "APTO101"
#define WIFI_PASSWORD "chmL231618"

#define DATABASE_URL "https://environment-meter-dragon-6235c-default-rtdb.firebaseio.com/"
#define API_KEY "AIzaSyDukadnVTFE8Gfeatz2cQhu_YReSLSKFF4"

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;
int count = 0;
bool signUp = false;

#include <Wire.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_BME280.h>
#include <Adafruit_Sensor.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

//sensor
#define SEALEVELPRESSURE_HPA (1013.25)
//leds
#define LED_PIN 21
#define LED_COUNT 10

//leds
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
//sensor
Adafruit_BME280 bme;

unsigned long delayTime;
int temperatura, pressao, altitude, umidade;

void setup()
{
    Serial.begin(9600);
    
    Serial.println("Setando os LEDS.....");
    strip.begin();
    strip.show();
    strip.setBrightness(50);
    
    Serial.println("LEDs ok, setando sensor.......");
    bool status;
    status = bme.begin(0x76);
    if(!status){
      Serial.println("Não foi possível encontrar um sensor BME280 válido, tente reconectar os fios");
      while(1);
    }
    Serial.println("BME280 setado");

    delayTime = 3000;
}

void loop()
{
    valoresSensor();
    delay(delayTime);
    analiseDados();
}

void cascataLeds(uint32_t color, int wait)
{
    for (int i = 0; i < strip.numPixels(); i++)
    {
        strip.setPixelColor(i, color);
        strip.show();
        delay(wait);
    }
}

void valoresSensor(){
  temperatura = bme.readTemperature();
  pressao = bme.readPressure() / 100.0F;
  altitude = bme.readAltitude(SEALEVELPRESSURE_HPA);
  umidade = bme.readHumidity();
  
  Serial.println("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" *C");
  Serial.println("Pressão: ");
  Serial.print(pressao);
  Serial.println(" hpa");
  Serial.println("Altitude: ");
  Serial.print(altitude);
  Serial.println(" m");
  Serial.println("Umidade: ");
  Serial.print(umidade);
  Serial.println(" %");
  
}

void analiseDados(){
  //temperatura
  if(temperatura > 30)
    cascataLeds(strip.Color(255,   0,   0), 50);
  if(temperatura < 30 && temperatura > 20)
    cascataLeds(strip.Color(0,   255,   0), 50);
  if(temperatura < 20)
    cascataLeds(strip.Color(0,   0,   255), 50);

  delay(delayTime);

  //umidade
  if(umidade < 25)
    cascataLeds(strip.Color(255,   0,   0), 50);
  else if(umidade > 50 && umidade < 80)
    cascataLeds(strip.Color(0,   255,   0), 50);
  else if(umidade > 80)
    cascataLeds(strip.Color(0,   0,   255), 50);

  delay(delayTime);

  //altitude
  if(altitude < 300)
    cascataLeds(strip.Color(0,   0,   255), 50);
  else if(altitude > 300 && altitude < 15000)
    cascataLeds(strip.Color(0,   255,   0), 50);
  else if(altitude > 15000)
    cascataLeds(strip.Color(240,   200,   0), 50);
  delay(delayTime);
}

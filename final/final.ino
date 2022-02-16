// sensores e leds
#include <Wire.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_BME280.h>
#include <Adafruit_Sensor.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
// thingspeak
#include <WiFi.h>
#include "secrets.h"
#include "ThingSpeak.h" // always include thingspeak header file after other header files and custom macros

//thingspeak
char ssid[] = SECRET_SSID;   // your network SSID (name) 
char pass[] = SECRET_PASS;   // your network password
int keyIndex = 0;            // your network key Index number (needed only for WEP)
WiFiClient  client;
unsigned long myChannelNumber = SECRET_CH_ID;
const char * myWriteAPIKey = SECRET_WRITE_APIKEY;

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

float temperatura = 20;
int umidade = 10;
float altitude = 50;

void setup() {
  Serial.begin(115200);

  //sensor
  bool status = bme.begin(0x76);
  if(!status){
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while(1);
  }
  delayTime = 1000;

  //thingspeak
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}

void loop() {

  sensors();
  connectsWifi();
  uploadsData();

  delay(20000);
}

void sensors(){
  if(bme.readTemperature() > 30)
    ledWire(strip.Color(255,   0,   0), 50);
  if(bme.readTemperature() < 30 && bme.readTemperature() > 20)
    ledWire(strip.Color(0,   255,   0), 50);
  if(bme.readTemperature() < 20)
    ledWire(strip.Color(0,   0,   255), 50);

  delay(5000);

  //umidade
  if(bme.readHumidity() < 25)
    ledWire(strip.Color(255,   0,   0), 50);
  else if(bme.readHumidity() > 50 && bme.readHumidity() < 80)
    ledWire(strip.Color(0,   255,   0), 50);
  else if(bme.readHumidity() > 80)
    ledWire(strip.Color(0,   0,   255), 50);

  delay(5000);

  //altitude
  if(bme.readAltitude(SEALEVELPRESSURE_HPA) < 300)
    ledWire(strip.Color(0,   0,   255), 50);
  else if(bme.readAltitude(SEALEVELPRESSURE_HPA) > 300 && bme.readAltitude(SEALEVELPRESSURE_HPA) < 15000)
    ledWire(strip.Color(0,   255,   0), 50);
  else if(bme.readAltitude(SEALEVELPRESSURE_HPA) > 15000)
    ledWire(strip.Color(240,   200,   0), 50);
  
  delay(5000);
}

void connectsWifi(){
  // wifi
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(SECRET_SSID);
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, pass);
      Serial.print(".");
      delay(5000);     
    } 
    Serial.println("\nConnected.");
  }
}

void uploadsData(){

  // seta campos
  ThingSpeak.setField(1, bme.readTemperature());
  ThingSpeak.setField(2, bme.readHumidity());
  ThingSpeak.setField(3, bme.readAltitude(SEALEVELPRESSURE_HPA));
  
  // escrita no thingspeak
  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if(x == 200){
    Serial.println("Channel update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
}

void ledWire(uint32_t color, int wait)
{
    for (int i = 0; i < strip.numPixels(); i++)
    {
        strip.setPixelColor(i, color);
        strip.show();
        delay(wait);
    }
}

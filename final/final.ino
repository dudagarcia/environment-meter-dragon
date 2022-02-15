#include <Wire.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_BME280.h>
#include <Adafruit_Sensor.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#include <WiFi.h>
#include "secrets.h"
#include "ThingSpeak.h" // always include thingspeak header file after other header files and custom macros

//sensor
#define SEALEVELPRESSURE_HPA (1013.25)
//leds
#define LED_PIN 21
#define LED_COUNT 10

//leds
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
//sensor
Adafruit_BME280 bme;

//climate variables
unsigned long delayTime;
int temperatura, pressao, altitude, umidade;

//thingspeak
char ssid[] = SECRET_SSID;   // your network SSID (name) 
char pass[] = SECRET_PASS;   // your network password
int keyIndex = 0;            // your network key Index number (needed only for WEP)
WiFiClient  client;
unsigned long myChannelNumber = SECRET_CH_ID;
const char * myWriteAPIKey = SECRET_WRITE_APIKEY;

int statusCode = 0;
int field[8] = {1,2,3,4,5,6,7,8};

void setup() {
  Serial.begin(115200);  //Initialize serial
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo native USB port only
  }
  
  WiFi.mode(WIFI_STA);   
  ThingSpeak.begin(client);  // Initialize ThingSpeak

  // Connect or reconnect to WiFi
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(SECRET_SSID);
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, pass); // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(5000);     
    } 
    Serial.println("\nConnected");
  }
}

void loop() {

  // set the fields with the values
  ThingSpeak.setField(1, temperatura);
  ThingSpeak.setField(2, pressao);
  ThingSpeak.setField(3, altitude);
  ThingSpeak.setField(4, umidade);

  // write to the ThingSpeak channel
  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if(x == 200){
    Serial.println("Channel update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
  
  statusCode = ThingSpeak.readMultipleFields(myChannelNumber);
    
  if(statusCode == 200)
  {
    // Fetch the stored data
    temperatura = ThingSpeak.getFieldAsInt(field[0]); // Field 1
    pressao = ThingSpeak.getFieldAsInt(field[1]); // Field 2
    altitude = ThingSpeak.getFieldAsInt(field[2]); // Field 2
    umidade = ThingSpeak.getFieldAsInt(field[3]); // Field 2
  }

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

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

//climate variables
unsigned long delayTime = 5000;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);  //Initialize serial
}

void loop() {
  int temperatura, altitude, umidade;
  valoresSensor(temperatura, altitude, umidade);
  delay(5000);
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

void valoresSensor(int temperatura, int altitude, int umidade){
  Serial.write("entrou");
  temperatura = bme.readTemperature());
  altitude = bme.readAltitude(SEALEVELPRESSURE_HPA);
  umidade = bme.readHumidity();

  Serial.println("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" *C");
  Serial.println("Altitude: ");
  Serial.print(altitude);
  Serial.println(" m");
  Serial.println("Umidade: ");
  Serial.print(umidade);
  Serial.println(" %");

  analiseDados(temperatura, altitude, umidade);
}

void analiseDados(int temperatura, int altitude, int umidade){
  //temperatura
  if(temperatura > 30)
    cascataLeds(strip.Color(255,   0,   0), 50);
  if(temperatura < 30 && temperatura > 20)
    cascataLeds(strip.Color(0,   255,   0), 50);
  if(temperatura < 20)
    cascataLeds(strip.Color(0,   0,   255), 50);

  delay(5000);

  //umidade
  if(umidade < 25)
    cascataLeds(strip.Color(255,   0,   0), 50);
  else if(umidade > 50 && umidade < 80)
    cascataLeds(strip.Color(0,   255,   0), 50);
  else if(umidade > 80)
    cascataLeds(strip.Color(0,   0,   255), 50);

  delay(5000);

  //altitude
  if(altitude < 300)
    cascataLeds(strip.Color(0,   0,   255), 50);
  else if(altitude > 300 && altitude < 15000)
    cascataLeds(strip.Color(0,   255,   0), 50);
  else if(altitude > 15000)
    cascataLeds(strip.Color(240,   200,   0), 50);
  
  delay(5000);
}

#include <Wifi.h>
#include <WebServer.h>
#include <Wire.h>
#include <AdaFruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define LED_PIN 21
#define LED_COUNT 10

AdaFruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
    clock_prescale_set(clock_div_1);
#endif

    Serial.begin(115200);
    Serial.println("Setando os LEDS.....");
    strip.begin();
    strip.show();
    strip.setBrightness(50);
    Serial.println("LEDs ok, setando sensor.......");
}

void loop()
{
}

void colorWipe(uint32_t color, int wait)
{
    for (int i = 0; i < strip.numPixels(); i++)
    {
        strip.setPixelColor(i, color);
        strip.show();
        delay(wait);
    }
}

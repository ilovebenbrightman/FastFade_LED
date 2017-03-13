#include <FastLED.h>
#include <Button.h>
#define NUM_LEDS 32
#define DATA_PIN 11
#define COLOR_ORDER GRB
#define divisor 3fdfdf
#define brightness 20
    
struct CRGB leds[NUM_LEDS];


void setup() 
{
  FastLED.addLeds<WS2812, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
}

void loop() 
{

  for (int colorStep=0; colorStep<256; colorStep = colorStep+2)
    {
      int h = colorStep;
      int s = 255;
      int v = 150;

        fill_solid(leds, NUM_LEDS, CHSV(h,s,v));
    FastLED.show();
    }
}

#include <FastLED.h>
#include <Button.h>
#define NUM_LEDS 32
#define DATA_PIN 11
#define COLOR_ORDER GRB
    
struct CRGB leds[NUM_LEDS];


void setup() 
{
  FastLED.addLeds<WS2812, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
}

void loop() 
{

/*Currently, this cycles through the entire color fade at a speed based on, i'm guessing, the clock speed of the teensyduino.
I would like instead for it to complete a cycle every 'n' milliseconds.  Even if that's faster than the clock speed of the teensyduino.
If that means I have to have a less-smooth fade, I'm okay with that, but I'd prefer the fade to be as smooth as possible
*/
        
  for (int colorStep=0; colorStep<256; colorStep = colorStep+2)
    {
      int h = colorStep;
      int s = 255;
      int v = 150;

        fill_solid(leds, NUM_LEDS, CHSV(h,s,v));
    FastLED.show();
    }
}

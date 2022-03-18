#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN            32

#define NUMPIXELS      10

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

  for(int i=0; i < NUMPIXELS ; i++){

     pixels.setPixelColor(i, pixels.Color(0,255,0));
 
      pixels.show(); 

     delay(DELAYVAL);

  }

    for(int i=0;i<NUMPIXELS;i++){

      pixels.setPixelColor(i, pixels.Color(255,0,0));
 
      pixels.show(); 

      delay(DELAYVAL);
  }
}

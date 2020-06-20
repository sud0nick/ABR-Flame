#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

/* Function Prototypes */
void setPixel(Adafruit_NeoPixel *strip, int Pixel, byte red, byte green, byte blue);
void setPixelHeatColor(Adafruit_NeoPixel *strip, int Pixel, byte temperature);
void fire(Adafruit_NeoPixel *strip, int Cooling, int Sparking, int SpeedDelay);
void showStrip(Adafruit_NeoPixel *strip);

Adafruit_NeoPixel left_flame = Adafruit_NeoPixel(10, 6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel right_flame = Adafruit_NeoPixel(13, 9, NEO_GRB + NEO_KHZ800);

void setup() {
  left_flame.begin();
  right_flame.begin();
  
  left_flame.show();
  right_flame.show();
}

void loop() {
  fire(&left_flame, 55, 120, 60);
  fire(&right_flame, 55, 120, 60);
}

/* *********************************** */
/* Adafruit Fire Code                  */
/* Modified to support multiple strips */
/* *********************************** */

void showStrip(Adafruit_NeoPixel *strip) {
  // NeoPixel
  strip->show();
}

void setPixel(Adafruit_NeoPixel *strip, int Pixel, byte red, byte green, byte blue) {
  // NeoPixel
  strip->setPixelColor(Pixel, strip->Color(red, green, blue));
}

void setPixelHeatColor(Adafruit_NeoPixel *strip, int Pixel, byte temperature) {
  // Scale 'heat' down from 0-255 to 0-191
  byte t192 = round((temperature/255.0)*191);
 
  // calculate ramp up from
  byte heatramp = t192 & 0x3F; // 0..63
  heatramp <<= 2; // scale up to 0..252
 
  // figure out which third of the spectrum we're in:
  if( t192 > 0x80) {                     // hottest
    setPixel(strip, Pixel, 255, 255, heatramp);
  } else if( t192 > 0x40 ) {             // middle
    setPixel(strip, Pixel, 255, heatramp, 0);
  } else {                               // coolest
    setPixel(strip, Pixel, heatramp, 0, 0);
  }
}

void fire(Adafruit_NeoPixel *strip, int Cooling, int Sparking, int SpeedDelay) {
  const int numPixels = strip->numPixels();
  byte heat[numPixels];
  int cooldown;
 
  // Step 1.  Cool down every cell a little
  for( int i = 0; i < strip->numPixels(); i++) {
    cooldown = random(0, ((Cooling * 10) / strip->numPixels()) + 2);
   
    if(cooldown>heat[i]) {
      heat[i]=0;
    } else {
      heat[i]=heat[i]-cooldown;
    }
  }
 
  // Step 2.  Heat from each cell drifts 'up' and diffuses a little
  for( int k= strip->numPixels() - 1; k >= 2; k--) {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
  }
   
  // Step 3.  Randomly ignite new 'sparks' near the bottom
  if( random(255) < Sparking ) {
    int y = random(7);
    heat[y] = heat[y] + random(160,255);
    //heat[y] = random(160,255);
  }

  // Step 4.  Convert heat to LED colors
  for( int j = 0; j < strip->numPixels(); j++) {
    setPixelHeatColor(strip, j, heat[j] );
  }

  showStrip(strip);
  delay(SpeedDelay);
}

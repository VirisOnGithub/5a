// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library
#include "FeatherShieldPinouts.h"

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        A0 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 10 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

uint32_t getNextColor() {
  static int step = 0;

  uint32_t color;

  switch (step) {
    case 0:
      color = pixels.Color(255, 0, 0);
      break;
    case 1:
      color = pixels.Color(0, 255, 0);
      break;
    case 2:
      color = pixels.Color(0, 0, 255);
      break;
  }

  step = (step + 1) % 3;

  return color;
}

uint32_t currentColor;

void IRAM_ATTR buttonISR () {
  currentColor = getNextColor();
}

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.
  pinMode(A2, INPUT);
  attachInterrupt(A2, buttonISR, RISING);
  pixels.setBrightness(10);

  currentColor = getNextColor();

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)

  Serial.begin(115200);
}

void loop() {
  pixels.clear(); // Set all pixel colors to 'off'
  
  Serial.println("Pixels cleared !");

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
    Serial.print("i = ");
    Serial.println(i);
    // if (digitalRead(A2)) {
    //   currentColor = getNextColor();
    // }

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    if (i != 0) {
      pixels.fill(currentColor, 0, i);
    }

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(DELAYVAL); // Pause before next pass through loop
  }
}

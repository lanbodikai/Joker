#include <WebUSB.h>
#include <Adafruit_NeoPixel.h>

WebUSB WebUSBSerial(1 /* https:// */, "webusb.github.io/arduino/demos");

#define Serial WebUSBSerial
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
#define LED_PIN    6
#define LED_COUNT 150
#define FADESPEED 5
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // Wait for serial port to connect.
  }
  Serial.println("Arduino USB serial port ready");
  Serial.flush();
  
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif

  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50);
}

void loop() {
  int command;
  if (Serial && Serial.available()) {
    command = Serial.read(); // Read the command from the Chrome web page
    // Serial.print() will send feed back data to Chrome via WebUSB for debugging
    Serial.print("Command ");
    Serial.print(command);
    Serial.print(" -> ");
    switch (command) {
      case 2: // The command code you defined
        // Write you codes to light uo teh LED strip
        colorWipe(strip.Color(255,0,0), 50); // Red
        Serial.println("Fascism");
        Serial.flush();
        break;
      case 3: // The command code you defined
        // Write you codes to light uo teh LED strip
        colorWipe(strip.Color(0,255,0), 50); // Green
        Serial.println("Republic");
        Serial.flush();
        break;
      case 0: // The command code you defined
        // Write you codes to light uo teh LED strip
        colorWipe(strip.Color(200, 5, 255), 50); // Purple
        Serial.println("Monarchy");
        Serial.flush();
        break;
      case 1: // The command code you defined
        // Write you codes to light uo teh LED strip
        colorWipe(strip.Color( 255, 255, 0), 50); // Yello
        Serial.println("Monarchy");
        Serial.flush();
        break;
      default: // Unknown command. Just for debugging
        Serial.println("Unknown...");
        Serial.flush();
    }
  }
}
void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    strip.setPixelColor(i+1, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    strip.setPixelColor(i+2, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(50);
    strip.clear();
    }
    strip.clear();
}

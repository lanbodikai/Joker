// Third-party WebUSB Arduino library
#include <WebUSB.h>
#include <Adafruit_NeoPixel.h>

WebUSB WebUSBSerial(1 /* https:// */, "webusb.github.io/arduino/demos");

#define Serial WebUSBSerial
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
#define LED_PIN    6
#define LED_COUNT 150
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
      case 0: // The command code you defined
        // Write you codes to light uo teh LED strip
        colorWipe(strip.Color(255,0,0), 50); // Red
        Serial.println("Fascism");
        Serial.flush();
        break;
      case 1: // The command code you defined
        // Write you codes to light uo teh LED strip
        colorWipe(strip.Color(0,255,0), 50); // Green
        Serial.println("Republic");
        Serial.flush();
        break;
      case 2: // The command code you defined
        // Write you codes to light uo teh LED strip
        colorWipe(strip.Color(200, 5, 255), 50); // Purple
        Serial.println("Monarchy");
        Serial.flush();
        break;
      case 3: // The command code you defined
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
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}
void theaterChase(uint32_t color, int wait) {
  for(int a=0; a<10; a++) {  // Repeat 10 times...
    for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
      strip.clear();         //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of strip in steps of 3...
      for(int c=b; c<strip.numPixels(); c += 3) {
        strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
      }
      strip.show(); // Update strip with new contents
    delay(wait);  // Pause for a moment
    }
  }
}

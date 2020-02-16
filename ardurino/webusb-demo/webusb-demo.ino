// Third-party WebUSB Arduino library
#include <WebUSB.h>

WebUSB WebUSBSerial(1 /* https:// */, "webusb.github.io/arduino/demos");

#define Serial WebUSBSerial

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // Wait for serial port to connect.
  }
  Serial.println("Arduino USB serial port ready");
  Serial.flush();
}

void loop() {
  int command;
  if (Serial && Serial.available()) {
    command = Serial.read();
    // Serial.print() will send feed back data to Chrome via WebUSB for debugging
    Serial.print("Command ");
    Serial.print(command);
    Serial.print(" -> ");
    switch (command) {
      case 0:
        // Write you codes to light uo teh LED strip
        Serial.println("Democracy");
        Serial.flush();
        break;
      case 1:
        // Write you codes to light uo teh LED strip
        Serial.println("Communism");
        Serial.flush();
        break;
      default:
        Serial.println("Unknown...");
        Serial.flush();
    }
  }
}

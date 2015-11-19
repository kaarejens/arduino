/* Serial Hardware Monitor for 4Display-Shield-22
 *  written by tirrit
 *  
 *  TODO:
 *  
 *  - baudrate option
 *  - refresh option
 *  - input option from software serial
 *  
 */
#if defined(ARDUINO) && (ARDUINO >= 100)
#include "Arduino.h" // for Arduino 1.0
#else
#include "WProgram.h" // for Arduino 23
#endif

#include "SPI.h"
#include "screen_4D_22_library.h"

screen22 myScreen(_4DSHIELD22);
uint16_t x, y;

String bufferen = "";
boolean stringComplete = false;
int counter = 0;

void setup() 
{
  myScreen.begin();
  bufferen.reserve(200);
  myScreen.setOrientation(3);
  myScreen.text(30, 40, "Hardware Serial Monitor", greenColour, blackColour, 1, 2);
  myScreen.text(45, 60, "Version 0.1", greenColour, blackColour, 1, 1);
  myScreen.text(50, 150, "Gaze Electronics 2015", greenColour, blackColour, 1, 2);
  delay(1000);
  myScreen.clear();
  Serial.begin(115200);
  Serial.println("ready.");
}

void serialEvent()
{
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    bufferen += inChar;
    if (inChar == '\n') {
      stringComplete = true;
      counter++;
    }
  }
}

void loop() 
{
  serialEvent();

  if (stringComplete) {
    if (counter == 1) {
      myScreen.text(0, 0, bufferen, greenColour, blackColour, 1, 1);
    } else if (counter == 2) {
      myScreen.text(0, 10, bufferen, greenColour, blackColour, 1, 1);
    } else if (counter == 3) {
      myScreen.text(0, 20, bufferen, greenColour, blackColour, 1, 1);
    } else if (counter == 4) {
      myScreen.text(0, 30, bufferen, greenColour, blackColour, 1, 1);
    } else if (counter == 5) {
      myScreen.text(0, 40, bufferen, greenColour, blackColour, 1, 1);
    } else if (counter == 6) {
      myScreen.text(0, 50, bufferen, greenColour, blackColour, 1, 1);
    } else if (counter == 7) {
      myScreen.text(0, 60, bufferen, greenColour, blackColour, 1, 1);
    } else if (counter == 8) {
      myScreen.text(0, 70, bufferen, greenColour, blackColour, 1, 1);
    } else if (counter == 9) {
      myScreen.text(0, 80, bufferen, greenColour, blackColour, 1, 1);
    } else if (counter == 10) {
      myScreen.text(0, 90, bufferen, greenColour, blackColour, 1, 1);
    } else if (counter == 11) {
      myScreen.text(0, 100, bufferen, greenColour, blackColour, 1, 1);
    } else if (counter == 12) {
      myScreen.text(0, 110, bufferen, greenColour, blackColour, 1, 1);
    } else if (counter == 13) {
      myScreen.text(0, 120, bufferen, greenColour, blackColour, 1, 1);
    } else if (counter == 14) {
      myScreen.text(0, 130, bufferen, greenColour, blackColour, 1, 1);
    } else if (counter == 15) {
      myScreen.text(0, 140, bufferen, greenColour, blackColour, 1, 1);
    } else if (counter == 16) {
      myScreen.text(0, 150, bufferen, greenColour, blackColour, 1, 1);
    } else if (counter == 17) {
      myScreen.text(0, 0, bufferen, greenColour, blackColour, 1, 1);
      counter = 1;
    }
    bufferen = "";
    stringComplete = false;
  }
}

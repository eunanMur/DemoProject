#include <Servo.h>
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 255;
const int colorG = 125;
const int colorB = 0;
bool isBroken = false; // initial state of distance
bool switch1 = false;
bool switch2 = false;

void setup() {
  Serial.begin(9600);
  pinMode(6, INPUT);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  lcd.setRGB(colorR, colorG, colorB);
  lcd.print("Bad Job "); // initial message on startup
}

void loop() {
  while (1) {
    delay(500);
    if (digitalRead(6) == LOW) {
      if (!isBroken) { // check if distance was just broken
        lcd.clear(); // clear the display
        lcd.print("Wahup ");
        isBroken = true; // set distance state to broken
        switch1 = true;
        switch2 = false;
      }
    } else {
      if (isBroken) { // check if distance was just restored
        if (switch1)
        isBroken = false; // set distance state to not broken
        lcd.clear(); // clear the display
        lcd.print("Bad Job ");
        switch1 = false;
        switch2 = true;
       
      }
    }
  }
}
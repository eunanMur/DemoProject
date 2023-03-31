#include <Wire.h>
#include "rgb_lcd.h"
#include <Servo.h> 


rgb_lcd lcd;

int servoPin = 3;

const int irPin = 6;
const int colorR = 255;
const int colorG = 125;
const int colorB = 0;

Servo Servo1; 

bool isLocked = true;

void setup() {
  Serial.begin(9600);
  Servo1.attach(servoPin); 
  pinMode(irPin, INPUT);
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  lcd.print("Locked");
}

void loop() {
  if (digitalRead(irPin) == LOW) {
    isLocked = !isLocked;
    if (isLocked) {
      lcd.clear();
      lcd.setRGB(255, 0, 0); // set background color to red
      lcd.print("Locked");
      Servo1.write(0); 
    } else {
      lcd.clear();
      lcd.setRGB(0, 255, 0); // set background color to green
      lcd.print("Unlocked");
      Servo1.write(90); 
    }
    delay(1000);
  }
}
#include <Wire.h>

const int buttonPin = 12;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  // send signals to second arduino when button pressed
  if (digitalRead(buttonPin) == LOW) {
    Wire.beginTransmission(8);
    Wire.write('1');
    Wire.endTransmission();
  }
}
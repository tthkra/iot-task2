#include <Wire.h>

const int ledPin = 13;

void setup() {
  Serial.begin(9600);
  // connect to second arduino
  Wire.begin(8); 
  // call event function when data is recieved
  Wire.onReceive(Event);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {

}

void Event(int numBytes) {
  while (Wire.available()) {
    char signal = Wire.read();
    // turn on the led if button pressed
    if (signal == '1') {
      digitalWrite(ledPin, HIGH);
      
      delay(1000); 
      digitalWrite(ledPin, LOW);
    }
  }
}

// Move servo with library

#include <Servo.h>

int sPin = 9; // Servo should be connected to 9

Servo servo; // Declare servo object

void setup() {
  Serial.begin(9600);
  servo.attach(sPin);
}

void loop() {
  servo.write(0);
  delay(500);
  servo.write(180);
  delay(1000);
}

// Servo that moves light switch when movement is detected

#include <Servo.h>

const int pirPin = 3;
const int servoPin = 9;

int pirValue;
int pirState = LOW;

int servoTime = 1500;
int servoAngle = 180;
int counter; // Servo movement counter

int timerInterval = 1000;
int previousTime = 0;

class Sweeper {
    Servo servo;              // the servo
    int pos;              // current servo position
    int moveTo;           // Where to move the servo
    int  updateInterval;      // interval between updates
    unsigned long lastUpdate; // last update of position
    int servoCounter;

  public:
    Sweeper(int interval, int degree) {
      updateInterval = interval;
      moveTo = degree;
      servoCounter = 0;
    }

    void Attach(int pin) {
      servo.attach(pin);
    }

    void Detach() {
      servo.detach();
    }

    int Read() {
      servo.read();
    }

    void Write(int whereTo) {
      servo.write(whereTo);
    }

    void ResetCounter() {
      servoCounter = 0;
    }
    
    void Move() {
      if ((millis() - lastUpdate) > updateInterval) {
        lastUpdate = millis();
        pos = moveTo;
        servo.write(pos);
        if (servo.read() == pos)  {
          // reverse direction
          moveTo = 180 - moveTo;
        }
      }
    }
};

Sweeper servo1(servoTime, servoAngle);

void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  servo1.Write(0);
}

void loop() {
  pirValue = digitalRead(pirPin);
  if (pirValue == HIGH) {
    servo1.Attach(servoPin);
    servo1.Move();
  } else {
    servo1.Detach();
  }
}



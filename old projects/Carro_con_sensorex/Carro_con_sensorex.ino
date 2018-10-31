#include <Ultrasonic.h>

const int A_1A = 2;
const int A_1B = 3;
const int A_2A = 4;
const int A_2B = 5;

Ultrasonic ultrasonic(7,8);

//Variable de distancia
long distancia;

void setup()
{
  Serial.begin(9600);
  pinMode(A_1A, OUTPUT);
  pinMode(A_1B, OUTPUT);
  pinMode(A_2A, OUTPUT);
  pinMode(A_2B, OUTPUT);
  
  digitalWrite(A_1A, 0);
  digitalWrite(A_1B, 0);
  digitalWrite(A_2A, 0);
  digitalWrite(A_2B, 0);
}
void loop()
{
  distancia = ultrasonic.Ranging(CM);
  
  if (distancia >= 35) {
    //digitalWrite(A_1A, 255);
    digitalWrite(A_1B, 255);
    //digitalWrite(A_2A, 255);
    digitalWrite(A_2B, 255);
  } else if(distancia<=34) {
    digitalWrite(A_1A, 0);
    digitalWrite(A_1B, 0);
    digitalWrite(A_2A, 0);
    digitalWrite(A_2B, 0);
    delay(300);
    
    digitalWrite(A_1A, 0);
    digitalWrite(A_1B, 0);
    digitalWrite(A_2A, 0);
    digitalWrite(A_2B, 255);
    delay(300);
  }
    
}

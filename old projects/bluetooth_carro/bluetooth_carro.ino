#include <SoftwareSerial.h>
#include <Ultrasonic.h>

const int rxpin = 13;
const int txpin = 12;

const int A_1A = 2;
const int A_1B = 3;
const int A_2A = 4;
const int A_2B = 5;


SoftwareSerial bluetooth(rxpin, txpin);

Ultrasonic ultrasonic(7,8);

//Variable de distancia
long distancia;

void setup()
{
  Serial.begin(9600);
  bluetooth.begin(9600);
  Serial.println("Serial listo");
  bluetooth.println("Bluetooth listo");
  
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
  if (bluetooth.available()){
     char c = (char)bluetooth.read();
    Serial.write(c);
    Serial.println(c);
   
  switch (c){
      case 'a': //izquierda
      digitalWrite(A_1A, 0);
      digitalWrite(A_1B, 0);
      digitalWrite(A_2A, 0);
      digitalWrite(A_2B, 255);
      delay(300);
      digitalWrite(A_1A, 0);
      digitalWrite(A_1B, 0);
      digitalWrite(A_2A, 0);
      digitalWrite(A_2B, 0);
      break;
     case 'w': //adelante
      digitalWrite(A_1A, 0);
      digitalWrite(A_1B, 255);
      digitalWrite(A_2A, 0);
      digitalWrite(A_2B, 255);
      break;
     case 'd': //derecha
      digitalWrite(A_1A, 0);
      digitalWrite(A_1B, 255);
      digitalWrite(A_2A, 0);
      digitalWrite(A_2B, 0);
      delay(300);
      digitalWrite(A_1A, 0);
      digitalWrite(A_1B, 0);
      digitalWrite(A_2A, 0);
      digitalWrite(A_2B, 0);
      break;
     case 's': //abajo
      digitalWrite(A_1A, 255);
      digitalWrite(A_1B, 0);
      digitalWrite(A_2A, 255);
      digitalWrite(A_2B, 0);
      break;
     case 'o': //parar
      digitalWrite(A_1A, 0);
      digitalWrite(A_1B, 0);
      digitalWrite(A_2A, 0);
      digitalWrite(A_2B, 0);
      break;
    }   
  } 
}

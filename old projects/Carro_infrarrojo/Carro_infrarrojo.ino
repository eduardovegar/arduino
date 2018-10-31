#include <IRremote.h>
#include <Ultrasonic.h>

int pinIR = 9;
IRrecv miReceptor (pinIR);
decode_results resultado;

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
  miReceptor.enableIRIn();
  
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
  if (miReceptor.decode(&resultado))
  {
    Serial.println(resultado.value);
    miReceptor.resume();
    delay(250);
    }
    if (distancia >= 35) {
   switch (resultado.value){
      case 16720605: //izquierda
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
     case 16736925: //adelante
      digitalWrite(A_1A, 0);
      digitalWrite(A_1B, 255);
      digitalWrite(A_2A, 0);
      digitalWrite(A_2B, 255);
      break;
     case 16761405: //derecha
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
     case 16754775: //abajo
      digitalWrite(A_1A, 255);
      digitalWrite(A_1B, 0);
      digitalWrite(A_2A, 255);
      digitalWrite(A_2B, 0);
      break;
     case 16712445: //parar
      digitalWrite(A_1A, 0);
      digitalWrite(A_1B, 0);
      digitalWrite(A_2A, 0);
      digitalWrite(A_2B, 0);
      break;
    }   
  } else if(distancia<=34) {
    digitalWrite(A_1A, 0);
    digitalWrite(A_1B, 0);
    digitalWrite(A_2A, 0);
    digitalWrite(A_2B, 0);
    delay(300);
    
    digitalWrite(A_1A, 255);
    digitalWrite(A_1B, 0);
    digitalWrite(A_2A, 255);
    digitalWrite(A_2B, 0);
    delay(500);
    
    digitalWrite(A_1A, 0);
    digitalWrite(A_1B, 0);
    digitalWrite(A_2A, 0);
    digitalWrite(A_2B, 0);
    delay(300);
    
    digitalWrite(A_1A, 0);
    digitalWrite(A_1B, 255);
    digitalWrite(A_2A, 0);
    digitalWrite(A_2B, 0);
    delay(300);
    digitalWrite(A_1A, 0);
    digitalWrite(A_1B, 0);
    digitalWrite(A_2A, 0);
    digitalWrite(A_2B, 0);
    
    digitalWrite(A_1A, 0);
    digitalWrite(A_1B, 255);
    digitalWrite(A_2A, 0);
    digitalWrite(A_2B, 255);
    
    switch (resultado.value){
    case 16720605: //izquierda
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
     case 16736925: //adelante
      digitalWrite(A_1A, 0);
      digitalWrite(A_1B, 255);
      digitalWrite(A_2A, 0);
      digitalWrite(A_2B, 255);
      break;
     case 16761405: //derecha
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
     case 16754775: //abajo
      digitalWrite(A_1A, 255);
      digitalWrite(A_1B, 0);
      digitalWrite(A_2A, 255);
      digitalWrite(A_2B, 0);
      break;
     case 16712445: //parar
      digitalWrite(A_1A, 0);
      digitalWrite(A_1B, 0);
      digitalWrite(A_2A, 0);
      digitalWrite(A_2B, 0);
      break;
  }
  }
    
}  



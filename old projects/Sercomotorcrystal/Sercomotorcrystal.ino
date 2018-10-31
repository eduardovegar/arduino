#include <Servo.h>

int cosa;
int c1 = 1234;
int c2 = 2341;
int c3 = 3412;
int c4 = 4123;
int c5 = 56789;
Servo motor;



void setup(){
  Serial.begin(9600);
  Serial.println("Bienvenido");
  motor.attach(9);
  motor.write(0);
  delay(100);
    motor.write(180);
    delay(100);
      motor.write(0);
      delay(100);
}

void loop(){
  
  
  delay(500);
  
   if(Serial.available()>0){
     
     Serial.println("Introduzca la contra: ");
     
//     cosa = Serial.read();
     int c = Serial.parseInt();
     switch (c){
       case 1234: c=c1;
               motor.write(180);
               delay(6000);
               motor.write(0);
               Serial.println("Contra correcta"+c);
               break;
               
      case 2341:   c=c2;
               motor.write(180);
               delay(6000);
               Serial.println("Contra correcta"+c);
               break;
               
               
       case 3412:   c=c3;
               motor.write(180);
               delay(6000);
               Serial.println("Contra correcta"+c);
               break;
               
               
               
        case 4123:   c=c4;
               motor.write(180);
               delay(6000);
               Serial.println("Contra correcta"+c);
               break;
               
        
        case 56789:   c=c5;
               motor.write(180);
               delay(6000);
               Serial.println("Contra correcta"+c);
               break;


     }
    
   }
}

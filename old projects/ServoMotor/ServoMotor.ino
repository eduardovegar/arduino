#include <Servo.h>

//Define object
Servo motorSer;

void setup() {
  //Where
  motorSer.attach(9);
}

void loop(){
  //Indicate positions
  motorSer.write(110);
  delay(500);
  
  motorSer.write(70);
  delay(500);
  
  motorSer.write(95);
  delay(500);
  
  motorSer.write(80);
  delay(500);
  
  motorSer.write(0);
  delay(500);
 
  
}

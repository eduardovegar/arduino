// trying to receive and store in array

#include <IRremote.h>

int IR_PIN  = 11;

IRrecv receive(IR_PIN);

boolean recording = true;
decode_results results;

void setup(){
  Serial.begin(9600);
  receive.enableIRIn();
}

void loop(){
  if (recording){
    if (receive.decode(&results)){
      Serial.println("received data");
      Serial.println(results.rawlen);
      Serial.println(results.rawbuf);
    }
  }
}


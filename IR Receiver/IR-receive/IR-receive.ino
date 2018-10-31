#include <IRremote.h>


void setup() {
 
 IRsend irsend;

}

void loop() {
  IRrecv irrecv(11);
  irrecv.enableIRIn();
  Serial.println(irrecv.decode());
  irrecv.resume();
}

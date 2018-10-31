// IR Send for Honeywell Fan

#include <IRremote.h>
IRsend irsend;

void setup() {

}

void loop() {
  int khz = 38;
  unsigned int fanSignal[] = {1250, 400, 1250, 400, 450, 1250, 1250, 400, 1250, 400, 1250, 450, 400, 1250, 400, 1250, 450, 1250, 1250, 400, 1250, 400, 450}; 
  unsigned int onSignal[] = {1250, 450, 1250, 400, 400, 1250, 1250,450, 1250, 400, 400, 1250, 450, 1250, 400, 1250, 400, 1250, 1250, 400, 450, 1250, 400};
  unsigned int roSignal[] = {1250, 400, 1250, 450, 400, 1250, 1250, 400, 1250, 450, 1250, 400, 400, 1250, 450, 1250, 400, 1250, 400, 1250, 1250, 400, 1300};
  irsend.sendRaw(onSignal, sizeof(onSignal) / sizeof(onSignal[0]), khz);
  delay (1000); 
}

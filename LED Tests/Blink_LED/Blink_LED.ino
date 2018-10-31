/** Blink and Test an LED **/

int led = 11;
int brightness = 0;
int fadeAmount = 1;
void setup(){
  pinMode(led, OUTPUT);
}

void loop(){
   // set the brightness of pin 9:
  analogWrite(led, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(10);
}

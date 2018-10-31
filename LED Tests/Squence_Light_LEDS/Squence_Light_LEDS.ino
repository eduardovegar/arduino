// Various LEDs

int ledPins[] = {2,3,4,5,6,7,8,9,10}; // array to store all leds

void setup(){
  for(int i=0; i<9; i++){ // loop to set each led for each pin
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop(){
 
}
 
void sequenceLoop(){
  int delayTime = 30; 
  
  // Start turing them on
  for (int i=0; i <= 8; i++){
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
  }
  
  // sequencially turning off
  for (int i=8;, i>=0; i--){
    digitalWrite(ledPins[i], LOW);
    delay(delayTime);
  } 
}

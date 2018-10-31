
// HC-SR501 Motion Detector
// Sample Sketch

int led = 8;  // LED on pin 8
int pir = 3; // Define  Input for HC-SR501

int pirValue; // Place to store read PIR Value
int timer; // timer variable
int val = 0;  // reading pin status variable
int pirState = LOW; // Assume no motion detected
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(pir, INPUT);
 
  digitalWrite(led, LOW);  
}

void loop() {
  val = digitalRead(pir);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(led, HIGH);  // turn LED ON
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
    digitalWrite(led, LOW); // turn LED OFF
    if (pirState == HIGH){
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
  
  // Read PIR by analog form
  /*
  pirValue = analogRead(pir);
  int pirValueMap = map(pirValue, 0, 1023, 0, 255);

  Serial.print(pirValue);
  Serial.print(" / ");
  Serial.println(pirValueMap);
  analogWrite(led, pirValueMap);
  delay(100);
  */
  // Read PIR by digital form
  /*pirValue = digitalRead(pir);
  digitalWrite(led, pirValue);
  */
  // How long is it detecting motion
  /*
  if (pirValue == HIGH){
      timer++;
      delay(1000);
      Serial.println(timer);
    }
  if (pirValue == LOW) {
      timer = 0;
    }
    */
}


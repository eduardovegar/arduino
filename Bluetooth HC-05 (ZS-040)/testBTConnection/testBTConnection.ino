int state = 0;
int led =8;

void setup() {
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  Serial.begin(9600); // Default BT Rate
}

void loop(){
  if(Serial.available()) { // Check if data is coming from serial port
    state = Serial.read(); // Read data
  }

  if (state == '0'){
    digitalWrite(led, LOW);
    Serial.println("LED OFF");
    state = 0;
  } else if (state == '1'){
    digitalWrite(led, HIGH);
    Serial.println("LED ON");
    state = 0;  
  }
}

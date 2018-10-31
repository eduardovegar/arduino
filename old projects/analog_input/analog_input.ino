int lectura_int = 0;
float lectura_float = 0;

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  lectura_int = analogRead(A0);
  Serial.print("Lecutra usando variable Int=");
  Serial.println(lectura_int);
  
  lectura_float = analogRead(A0);
  Serial.print("Lectura usando variable Float=");
  Serial.println(lectura_float);
  
  Serial.println("**********************************");
  
  delay(1000);
  
}



// initialize indicator variables
int i = 0;
int i2 = 0;
int i3 = 0; 

void setup() {
  // Initialize LED Groups
  // 4 = Center
  // 8 = Temp Center Left/Right Sides
  // 11 = Left Side Down
  // 12 = Right Side Down
  // 6 = left side up
  // 10 = right side up
  pinMode(4, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT); 
}

void loop() {
  // cascade loop
  while (i < 20) {
    digitalWrite(6, HIGH);
    digitalWrite(10, HIGH);
    delay(100);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    delay(200);
    digitalWrite(4, HIGH);
    delay(100);
    digitalWrite(8, HIGH);
    delay(100);
    digitalWrite(6, LOW);
    digitalWrite(10, LOW);
    delay(200);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    delay(100);
    digitalWrite(4, LOW);
    digitalWrite(8, LOW);
    delay(200);
    i++;
  }
  i = 0;
  // flashing loop
  while (i2 < 10) {
    digitalWrite(4, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    delay(500);
    digitalWrite(4, LOW);
    digitalWrite(8, LOW);
    digitalWrite(6, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    delay(200);
    i2++;
  }
  i2 = 0;
  // on for a while
  while (i3 < 30){
    digitalWrite(4, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    delay(500);
    i3++;
  }
  i3=0;
  digitalWrite(4, LOW);
  digitalWrite(8, LOW);
  digitalWrite(6, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
}

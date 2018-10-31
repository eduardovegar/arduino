int lightIn = 0;
int led = 9;

void setup() {
    pinMode(led, OUTPUT);
    pinMode(lightIn, INPUT);
  }
void loop() {
   int lightLevel = analogRead(lightIn);

   lightLevel = map(lightLevel, 0, 900, 0, 255);
   lightLevel = constrain(lightLevel, 0, 255);

   analogWrite(led, lightLevel);
  }

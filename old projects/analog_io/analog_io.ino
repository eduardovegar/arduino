int ledPin= 9;
int lecturaPot = 0;

void setup()
{
pinMode(ledPin, OUTPUT);
}

void loop()
{
lecturaPot = (analogRead(0));
lecturaPot = lecturaPot/4;
analogWrite(ledPin, lecturaPot);
delay(50);
}

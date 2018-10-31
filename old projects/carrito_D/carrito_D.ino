const int A_A1 = 2;
const int A_1B = 3;
const int B_B1 = 5;
const int B_B2 = 6;

void setup()
{
  pinMode(A_A1, OUTPUT);
  pinMode(A_1B, OUTPUT);
  pinMode(B_B1, OUTPUT);
  pinMode(B_B2, OUTPUT);
  
  analogWrite(A_A1, 0); digitalWrite(A_1B, 0);
  analogWrite(B_B1, 0); digitalWrite(B_B2, 0);
}
void loop()
{
  analogWrite(A_A1, 255); digitalWrite(A_1B, 0);
  analogWrite(B_B1, 255); digitalWrite(B_B2, 0);
  delay(3000);
  
  analogWrite(A_A1, 0); digitalWrite(A_1B, 0);
  analogWrite(B_B1, 0); digitalWrite(B_B2, 0);
  delay(1000);
  
  analogWrite(A_A1, 0); digitalWrite(A_1B, 255);
  analogWrite(B_B1, 0); digitalWrite(B_B2, 255);
  delay(3000);
  
  analogWrite(A_A1, 0); digitalWrite(A_1B, 0);
  analogWrite(B_B1, 0); digitalWrite(B_B2, 0);
  delay(1000);
  
  analogWrite(A_A1, 126); digitalWrite(A_1B, 0);
  analogWrite(B_B1, 126); digitalWrite(B_B2, 0);
  delay(3000);
  
  analogWrite(A_A1, 0); digitalWrite(A_1B, 126);
  analogWrite(B_B1, 0); digitalWrite(B_B2, 126);
  delay(3000);
  
  analogWrite(A_A1, 0); digitalWrite(A_1B, 0);
   analogWrite(B_B1, 0); digitalWrite(B_B2, 0);
  delay(100);
  
  for (int x=0; x<256; x++)
  {
    analogWrite(A_A1, x); digitalWrite(A_1B, 0);
    analogWrite(B_B1, x); digitalWrite(B_B2, 0);
    delay(250);
  }
  analogWrite(A_A1, 0); digitalWrite(A_1B, 0);
  analogWrite(B_B1, 0); digitalWrite(B_B2, 0);
  delay(1000);
}

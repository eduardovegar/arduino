const int A_1A = 2;
const int A_1B = 3;
const int A_2A = 4;
const int A_2B = 5;

void setup()
{
  pinMode(A_1A, OUTPUT);
  pinMode(A_1B, OUTPUT);
  pinMode(A_2A, OUTPUT);
  pinMode(A_2B, OUTPUT);
  
  digitalWrite(A_1A, 0);
  digitalWrite(A_1B, 0);
  digitalWrite(A_2A, 0);
  digitalWrite(A_2B, 0);
}
void loop()
{
  //digitalWrite(A_1A, 255);
  digitalWrite(A_1B, 255);
  //digitalWrite(A_2A, 255);
  digitalWrite(A_2B, 255);
  delay(300);
  
  digitalWrite(A_1A, 0);
  digitalWrite(A_1B, 0);
  digitalWrite(A_2A, 0);
  digitalWrite(A_2B, 0);
  delay(300);
  
  digitalWrite(A_1A, 0);
  digitalWrite(A_1B, 0);
  digitalWrite(A_2A, 0);
  digitalWrite(A_2B, 255);
  delay(300);
  
  digitalWrite(A_1A, 0);
  digitalWrite(A_1B, 0);
  digitalWrite(A_2A, 0);
  digitalWrite(A_2B, 0);
  delay(300);
  
  digitalWrite(A_1A, 0);
  digitalWrite(A_1B, 255);
  digitalWrite(A_2A, 0);
  digitalWrite(A_2B, 0);
  delay(300);
  
  digitalWrite(A_1A, 0);
  digitalWrite(A_1B, 0);
   digitalWrite(A_2A, 0);
  digitalWrite(A_2B, 0);
  delay(1000);  
  
  digitalWrite(A_1A, 255);
  //digitalWrite(A_1B, 255);
  digitalWrite(A_2A, 255);
  //digitalWrite(A_2B, 255);
  delay(300);
  
   digitalWrite(A_1A, 0);
  digitalWrite(A_1B, 0);
   digitalWrite(A_2A, 0);
  digitalWrite(A_2B, 0);
  delay(1000);  
}

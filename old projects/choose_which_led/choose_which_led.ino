int led1 = 2; 
int led2 = 3; 
int led3 = 4; 
int led4 = 5; 
int led5 = 6; 
int led6 = 7; 
int led7 = 8; 
int led8 = 9; 
int periodo = 250; 
int ingresoLed = 0; 
int numeroLed=0; 
 
void setup() { 
  Serial.begin(9600); 
  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT); 
  pinMode(led3, OUTPUT); 
  pinMode(led4, OUTPUT); 
  pinMode(led5, OUTPUT); 
  pinMode(led6, OUTPUT); 
  pinMode(led7, OUTPUT);  
  pinMode(led8, OUTPUT); 
  Serial.println("Ingrese que led quiere que parpadee."); 
} 
void loop() {
  if(Serial.available()>0) {
    digitalWrite(led1, LOW); 
    digitalWrite(led2, LOW); 
    digitalWrite(led3, LOW); 
    digitalWrite(led4, LOW);  
    digitalWrite(led5, LOW); 
    digitalWrite(led6, LOW); 
    digitalWrite(led7, LOW); 
    digitalWrite(led8, LOW); 
    
    ingresoLed = Serial.read(); 
    delay(250); 
    Serial.println(ingresoLed); 
    
    if(ingresoLed>'0'&&ingresoLed<'9') {
      numeroLed= (ingresoLed-'0'); 
      Serial.println(numeroLed); 
      
      for(int x=0; x<10; x++){
      
      digitalWrite(numeroLed+1, HIGH); 
      delay(periodo); 
      digitalWrite(numeroLed+1, LOW); 
      delay(periodo); } delay(1000); 
    
      Serial.println("Ingrese el número de led a parpadear"); 
    
       } else { 
         delay(1000); 
         Serial.println("error: ingrese número entre 1 y 8"); 
       } 
     }
   }

int led1=2;
int led2=3;
int led3=4;
int led4=5;
int led5=6;
int led6=7;
int led7=8;
int led8=9;
int cosa=0;

void setup(){
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  Serial.println("dame el arreglo que quieres que se reproduzca: 1-3");

}

void loop(){
 
 if(Serial.available()>0) {
  
   cosa= Serial.read();
  
  if(cosa=='1'){
    
    for(int i=0; i<=4; i++){
    
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led6, HIGH);
      digitalWrite(led7, HIGH);
      digitalWrite(led8, HIGH);
      delay(350);
      
      digitalWrite(led1, LOW);
      delay(200);
      digitalWrite(led2, LOW);
      delay(200);
      digitalWrite(led3, LOW);
      delay(200);
      digitalWrite(led4, LOW);
      delay(200);
      digitalWrite(led5, LOW);
      delay(200);
      digitalWrite(led6, LOW);
      delay(200);
      digitalWrite(led7, LOW);
      delay(200);
      digitalWrite(led8, LOW);
      delay(500);
      
      
    }
     
      
      
      Serial.println("dame otro arreglo: 1-3");
  }
  
  
  if(cosa=='2'){
    
     for(int i=0; i<=4; i++){
      
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, LOW);
      digitalWrite(led5, HIGH);
      digitalWrite(led6, LOW);
      digitalWrite(led7, HIGH);
      digitalWrite(led8, LOW);
      delay(700);
      
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, LOW);
      digitalWrite(led6, HIGH);
      digitalWrite(led7, LOW);
      digitalWrite(led8, HIGH);
      delay(700);
      
     }
    
      
      Serial.println("dame otro arreglo: 1-3");
  }
  
  
  if(cosa=='3'){
    for(int i=0; i<=4; i++){
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led6, LOW);
      digitalWrite(led7, LOW);
      digitalWrite(led8, LOW);
      delay(700);
      
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led6, LOW);
      digitalWrite(led7, LOW);
      digitalWrite(led8, HIGH);
      delay(200);
      
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led6, LOW);
      digitalWrite(led7, HIGH);
      digitalWrite(led8, HIGH);
      delay(200);
      
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led6, HIGH);
      digitalWrite(led7, HIGH);
      digitalWrite(led8, HIGH);
      delay(200);
      
       digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led6, HIGH);
      digitalWrite(led7, HIGH);
      digitalWrite(led8, HIGH);
      delay(200);
    }
      
      
      Serial.println("dame otro arreglo: 1-3");
  }
  
  
  
}
  
  
}

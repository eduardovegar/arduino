  #include "LedControl.h";
  
  const byte DIN=4;
  const byte CS=3;
  const byte CLK=2;
  const byte QTD_DISP=8;
  
  LedControl LedMatrix = LedControl(DIN, CLK, CS, QTD_DISP);  
  
  char mensaje[30];
  char charLeido;
  
  byte i=0, colo=0, row=0;
  int indice = 0;

 void setup(){
  Serial.begin(9600);
  LedMatrix.shutdown(0, false);
  LedMatrix.setIntensity(0, 10);
  LedMatrix.clearDisplay(0);
  
  Serial.print("Ingrese el mensaje...");

}

 void loop(){
  
  if (Serial.available() > 0) {
    charLeido = Serial.read();
    mensaje[indice] = charLeido;
    
    indice++;
    delay(250);
    
    if (Serial.available() == 0) {
    Serial.println("...desplegando mensaje.");
    delay(1000);
    
    LedMatrix.clearDisplay(0);
    LedMatrix.printStringScroll(0, 0 , mensaje, 75, '<');
    for (int x=0; x<=indice; x++) {
        mensaje[x] = 0;
      }
      indice = 0;
      Serial.println ("");
      Serial.println("Ingrese mensaje...");
    }
  }
}

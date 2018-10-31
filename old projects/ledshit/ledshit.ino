  #include "LedControl.h";
  
  const byte DIN=4;
  const byte CS=3;
  const byte CLK=2;
  const byte QTD_DISP=1;
  LedControl LedMatrix = LedControl(DIN, CLK, CS, QTD_DISP);  
  char texto[]="A VISA CRACK";
  byte i=0, col=0, row=0;
  
  

 void setup(){
  Serial.begin(9600);
  LedMatrix.shutdown(0, false);
  LedMatrix.setIntensity(0, 10);
  LedMatrix.clearDisplay(0);

}

 void loop(){
  
  LedMatrix.clearDisplay(0);
  
  for(i=0; i<8;i++){
    LedMatrix.setRow(0, i, B11111111);
    delay(100);
    LedMatrix.setRow(0, i, B00000000);
  } 
  
  LedMatrix.clearDisplay(0);
  
  for(i=0; i<8;i++){
    LedMatrix.setColumn(0, i, B11111111);
    delay(100);
    LedMatrix.setColumn(0, i, B00000000);
  } 
  
  LedMatrix.clearDisplay(0);
  
  for(col=0; col<8; col++){
    
    for(row=0; row<8; row++){
      LedMatrix.setLed(0, row, col, true);
      delay(20);
  }
  }
  
  for(row=0; row<8; row++){
    
    for(col=0; col<8; col++){
      LedMatrix.setLed(0, row, col, false);
      delay(20);
  }
  }
  
  LedMatrix.clearDisplay(0);
  LedMatrix.printChar(0, 0, 'c');
  delay(500);
  LedMatrix.printChar(0, 0, 'r');
  delay(500);
  LedMatrix.printChar(0, 0, 'a');
  delay(500);
  LedMatrix.printChar(0, 0, 'c');
  delay(500);
  LedMatrix.printChar(0, 0, 'k');
  delay(500);
  LedMatrix.printChar(0, 0, 'a');
  delay(500);
  LedMatrix.printChar(0, 0, 's');
  delay(500);
  LedMatrix.printChar(0, 0, 'o');
  delay(500);
  LedMatrix.printChar(0, 0, 's');
  delay(500);
 
  LedMatrix.clearDisplay(0);
  LedMatrix.printStringScroll(0,0, texto, 50, '<');
  delay(2000);

}

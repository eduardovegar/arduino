#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup(){
  lcd.begin(16, 2);

  lcd.setCursor(0, 0); 
  lcd.print("Hello world");
  lcd.setCursor(0, 1); 
  lcd.print("Prueba de pulsadores");
  delay(2000);
  lcd.clear();
}

void loop(){
  lcd.setCursor(0, 0);
  lcd.print("Press a button");
  
  int numeroBoton = leerPulsadores();
  lcd.setCursor(0, 1);

  switch(numeroBoton) {

    case 0:
    lcd.print("No button");
    delay(2000);
    break;
    
    case 1:
    lcd.print("RIGHT button");
    delay(2000);
    break;
    
    case 2:
    lcd.print("UP button");
    delay(2000);
    break;
    
    case 3:
    lcd.print("DOWN button");
    delay(2000);
    break;
    
    case 4:
    lcd.print("LEFT button");
    delay(2000);
    break;
    
    case 5:
    lcd.print("SELECT button");
    delay(2000);
    break;
    
    default:
    lcd.print("No button");
    delay(1000);
    break;
  }
}

int leerPulsadores() {
  int lectura_A0 = analogRead(0);
  
  if(lectura_A0 > 1000) return 0;
  if(lectura_A0 < 50) return 1;
  if(lectura_A0 < 195) return 2;
  if(lectura_A0 < 380) return 3;
  if(lectura_A0 < 555) return 4;
  if(lectura_A0 < 790) return 5;
  return 0;
                
}

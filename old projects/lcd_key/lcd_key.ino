#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
byte alegre[8] =
{
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};

void setup(){
  lcd.begin(16, 2);
  lcd.createChar(4, alegre);
  lcd.setCursor(0, 0);
  lcd.print("Hola mundo! Ufg");
  delay(2000);
  lcd.clear();
}

void loop(){
  lcd.setCursor(0, 1);
  lcd.print("Arduino + LCD");
  delay(2000);
  lcd.clear();
  
  int variable = 1234;
  lcd.setCursor(0, 0);
  lcd.print("La variable es: ");
  lcd.setCursor(4, 1);
  lcd.print(variable);
  delay(2000);
  lcd.clear();
  
  lcd.setCursor(7, 0);
  lcd.write(4);
  delay(2000);
  lcd.clear();
}

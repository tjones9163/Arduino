//https://www.makerguides.com/character-i2c-lcd-arduino-tutorial/

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4); 

int ledPin=9;
void setup()
{
  pinMode(ledPin,OUTPUT);
  
lcd.init();
  lcd.backlight();
}
void loop()
{
   
  lcd.setCursor(0, 0); 
  lcd.print("On");
  digitalWrite(ledPin,HIGH);
  delay(1000);
 lcd.clear();                 //NOTICE WHERE I PUT THE CLEAR()
  lcd.setCursor(0,0);
  lcd.print("Off");
  digitalWrite(ledPin,LOW);
  delay(1000);
lcd.clear();                   //NOTICE WHERE I PUT THE CLEAR()
}

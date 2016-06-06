 #include <Wire.h>  
#include <LiquidCrystal_I2C.h> // Using version 1.2.1

// The LCD constructor - address shown is 0x27 - may or may not be correct for yours
// Also based on YWRobot LCM1602 IIC V1
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  

void setup()
{
  lcd.begin(16,2); // sixteen characters across - 2 lines
  lcd.backlight();
  // first character - 1st line

}
 
 
void loop()
{ 
  lcd.setCursor(0,0);  
  lcd.print("herma");  
  delay(2000);  
   lcd.setCursor(0,1); 
   lcd.print(".");  
   delay(300); 
   lcd.setCursor(1,1); 
   lcd.print(".");  
   delay(300); 
   lcd.setCursor(2,1); 
   lcd.print(".");  
   delay(300);
  
  lcd.clear();
 
 lcd.setCursor(0,0);  
  lcd.print("agua");  
  delay(2000);  
   lcd.setCursor(0,1); 
   lcd.print(".");  
   delay(300); 
   lcd.setCursor(1,1); 
   lcd.print(".");  
   delay(300); 
   lcd.setCursor(2,1); 
   lcd.print(".");  
   delay(300); 

 lcd.clear();  
 lcd.setCursor(0,0);  
  lcd.print("ayuda"); 
  lcd.setCursor(0,1);  
  lcd.print("poema");   
  delay(2000);  
   lcd.setCursor(7,1); 
   lcd.print(".");  
   delay(300); 
   lcd.setCursor(8,1); 
   lcd.print(".");  
   delay(300); 
   lcd.setCursor(9,1); 
   lcd.print(".");  
   delay(300); 
    lcd.clear();
}


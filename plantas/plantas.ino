#include <Wire.h>  
#include <LiquidCrystal_I2C.h> // Using version 1.2.1
#include "DHT.h"
#define DHTPIN 7
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);  
// The LCD constructor - address shown is 0x27 - may or may not be correct for yours
// Also based on YWRobot LCM1602 IIC V1
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  

float Valor; 
float Valor2;   
float herma; 
float herma2;
void setup() {
Serial.begin(9600);
dht.begin();
}
void loop() {   
 lcd.begin(16,2); // sixteen characters across - 2 lines
  lcd.backlight();
  // first character - 1st line
  
  Serial.print("Sensor de Humedad valor:");  
Valor = analogRead(0); 
Valor2 = analogRead(1);   

herma= (1-Valor/1023)*100;
herma2= (1-Valor2/1023)*100; 

lcd.setCursor(0,0);  
lcd.print("Estado humedad ");  
lcd.setCursor(0,1);  
lcd.print("suelos: ");   
delay(1500); 
lcd.clear();  
 lcd.setCursor(0,0);  
lcd.print("planta 1 "); 
lcd.setCursor(0,1);  
lcd.print(herma);  
lcd.setCursor(7,1);  
lcd.print("%");  
delay(1500);
lcd.clear(); 

 lcd.setCursor(0,0);  
lcd.print("planta 2 "); 
lcd.setCursor(0,1);  
lcd.print(herma2);  
lcd.setCursor(7,1);  
lcd.print("%");  
delay(1500);
lcd.clear(); 




 

Serial.println(" planta 1:");  
Serial.print(herma);  
Serial.print("%");  
Serial.print(Valor); 
if (Valor <= 300)  
 
   Serial.println(" Encharcado");  
if ((Valor > 300) and (Valor <= 700)){  
    Serial.println(" Humedo, no regar");   
 lcd.setCursor(0,0);  
lcd.print("planta 1"); 
lcd.setCursor(0,1);  
lcd.print("no regar");  
delay(1500);
lcd.clear();  
} 
if (Valor > 700) { 
    Serial.println(" Seco, necesitas regar");   
lcd.setCursor(0,0);  
lcd.print("planta 1"); 
lcd.setCursor(0,1);  
lcd.print(" Regar");  
delay(1500);
lcd.clear();   
}
Serial.println("planta 2:");  
Serial.print(herma2);  
Serial.print("%"); 
Serial.print(Valor2); 
if (Valor2 <= 300){  
   Serial.println(" Encharcado");  
}
if ((Valor2 > 300) and (Valor2 <= 700)){  
    Serial.println(" Humedo, no regar"); 
    lcd.setCursor(0,0);  
lcd.print("planta 2"); 
lcd.setCursor(0,1);  
lcd.print("no regar");  
delay(1500);
lcd.clear();  
    
    }  
if (Valor2 > 700){  
    Serial.println(" Seco, necesitas regar");   
lcd.setCursor(0,0);  
lcd.print("planta 2"); 
lcd.setCursor(0,1);  
lcd.print(" Regar");  
delay(1500);
lcd.clear();


} 
  

int h = dht.readHumidity();// Lee la humedad
int t= dht.readTemperature();//Lee la temperatura
//////////////////////////////////////////////////Humedad
Serial.print("Humedad Relativa aire : ");                 
Serial.print(h);//Escribe la humedad
Serial.println(" %");                     
delay (500);
///////////////////////////////////////////////////Temperatura              
Serial.print("Temperatura: ");                  
Serial.print(t);//Escribe la temperatura
Serial.println(" C'");                   
delay (200);
///////////////////////////////////////////////////             

 lcd.setCursor(0,0);  
lcd.print("temperatura aire"); 
lcd.setCursor(0,1);  
lcd.print(t);  
lcd.setCursor(4,1);  
lcd.print("C");  
delay(1500);
lcd.clear();  

 
 lcd.setCursor(0,0);  
lcd.print("humadad Aire"); 
lcd.setCursor(0,1);  
lcd.print(h);  
lcd.setCursor(4,1);  
lcd.print("%");  
delay(1500);
lcd.clear(); 



                    
delay (200);
Serial.println ();
}
//Electrocrea.com

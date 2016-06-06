
#include "DHT.h"
#define DHTPIN 7
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);

float Valor; 
float Valor2;   
float herma; 
float herma2;
void setup() {
Serial.begin(9600);
dht.begin();
}
void loop() {  
  Serial.print("Sensor de Humedad valor:");  
Valor = analogRead(0); 
Valor2 = analogRead(1);   

herma= (1-Valor/1023)*100;
herma2= (1-Valor2/1023)*100;

Serial.println(" planta 1:");  
Serial.print(herma);  
Serial.print("%");  
Serial.print(Valor); 
if (Valor <= 300)  
 
   Serial.println(" Encharcado");  
if ((Valor > 300) and (Valor <= 700))  
    Serial.println(" Humedo, no regar");   
if (Valor > 700)  
    Serial.println(" Seco, necesitas regar");   
delay(1000);  
   
Serial.println("planta 2:");  
Serial.print(herma2);  
Serial.print("%"); 
Serial.print(Valor2); 
if (Valor2 <= 300)  
   Serial.println(" Encharcado");  
if ((Valor2 > 300) and (Valor <= 700))  
    Serial.println(" Humedo, no regar");   
if (Valor2 > 700)  
    Serial.println(" Seco, necesitas regar");   
delay(1000);  
  

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
                    
delay (200);
Serial.println ();
}
//Electrocrea.com

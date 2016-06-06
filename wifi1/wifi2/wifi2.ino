#include <SoftwareSerial.h>
SoftwareSerial BT1(3, 2); // RX | TX


String ordenes[]=
  {  "AT+CWMODE=3",
     "AT+CWQAP",
     "AT+CWJAP=\"bordeu gazmuri\",\"0703221450\"",
     "AT+CIFSR" ,
     "AT+CIPMUX=1",
     "AT+CIPSERVER=1,80",
     "END"                 // Para reconocer el fin de los comandos AT
  };



void setup() {
 int index = 0;
     while(ordenes[index] != "END")
        {  WIFI1.println(ordenes[index++]);
           while ( true)
              {   String s = GetLineWIFI();
                  if ( s!= "") Serial.println(s);
                  if ( s.startsWith("no change"))  
                          break;
                  if ( s.startsWith("OK"))  
                          break;
                  if ( s.startsWith("ready"))  
                         break;
                  // if (millis()-T >10000) break; 
              }
          Serial.println("....................");
      }





}

void loop() {
  // put your main code here, to run repeatedly:

}

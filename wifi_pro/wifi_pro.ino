#define SSID  "Jopapa"      //Tu SSDI
#define PASS  "xxxxxxxxx"  //Tu clave

void setup(){

Serial1.begin(9600);
Serial.begin(9600);  
Serial1.println("AT");
    if ( Serial1.find("OK")  ) {
        Serial.println("AT-->OK ");}     
delay(500); 
Serial1.println("AT+CWMODE=1");
delay(1000);  
  // conectar al router
boolean connected=false;
for(int i=0;i<5;i++){
  if(connectWiFi()){
   connected = true;
   break;}
}
/*Serial.println("AT+CWJAP=\"Jopapa\",\"xxxxxxxxxx\"");
Serial1.println("AT+CWJAP=\"Jopapa\",\"xxxxxxxxxx\"");
delay(2000);
while (!Serial1.find("OK")){
Serial.println("Conectando a Wifi");
Serial1.println("AT+CWJAP=\"Jopapa\",\"xxxxxxxxxx\"");
delay(2000);}
Serial.println("Modulo conectado a Wifi");
delay(1000);*/

Serial.println();

  //multiple connection mode
Serial1.println("AT+CIPMUX=1"); delay(100); 
  while ( Serial1.available() ) {
    Serial.write(Serial1.read());} 
Serial.println();    

Serial1.println("AT+CIPSERVER=1,80"); delay(100); 
  while ( Serial1.available() ) {
    Serial.write(Serial1.read());} 
Serial.println();     

  //La ip 
  Serial.print("IP:");
  Serial1.println("AT+CIFSR");
  delay(100);
  while ( Serial1.available() ) {
    Serial.write(Serial1.read());
  } 
  Serial.println();   
  Serial.println( "Start Webserver" );
}

  
void loop() {
  while (Serial1.available() >0 ){
   char c = Serial1.read();
   if (c == 71) {
    Serial.println("Enviada Web Request");
    webserver();
    delay(500);}
  }}


void http(String output){
  Serial1.print("AT+CIPSEND=0,");
  Serial1.println(output.length());
  if (Serial1.find(">")){
  Serial.println(output);
  Serial1.println(output); delay(10);
  while ( Serial1.available() > 0 ) {
    if ( Serial1.find("SEND OK")  ) {
        Serial.println("SEND OK");
      break; } 
  }}}


void webserver(void) {
char temp1[10];
dtostrf(analogRead(A0),1,2,temp1);
http("<H4>Value A0 = "+ String(temp1) +"</H4>\n");

dtostrf(analogRead(A1),1,2,temp1);
http("<H4>Value A1 = "+ String(temp1) +"</H4>\n");

Serial1.println("AT+CIPCLOSE=0"); 
  delay(500);
  while ( Serial1.available() > 0 ) {
    if ( Serial1.find("")  ) {
        Serial.println("");
      break; 
    } } }



boolean connectWiFi(){
String cmd="AT+CWJAP=\"";
cmd+=SSID;
cmd+="\",\"";
cmd+=PASS;
cmd+="\"";
Serial.println(cmd);
Serial1.println(cmd);
delay(2000);
if(Serial1.find("OK")){
  Serial.println("Conectado a WiFi");
  return true;}
else{
  Serial.println("No puede conectar a WiFi");
  return false;}
}

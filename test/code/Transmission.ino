#include <SoftwareSerial.h>
#include <Wire.h>

const int debit = 9600;
SoftwareSerial mySerial(4,3); //RX,TX   connectées sur TX,RX du XBEE


void setup() 
{
  Serial.begin(debit);
  mySerial.begin(debit);
  Serial.println("Test communication RS232 XBEE");
  delay(1000);
}

void loop() 
{
  Serial.println("envoie d'un caractere");
  mySerial.println("AAAAAAAAAAAA");
  delay(1000); 
  } 
  

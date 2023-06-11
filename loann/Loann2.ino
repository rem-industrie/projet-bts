#include <SoftwareSerial.h>
#include <Wire.h>

// XBEE S2C end device  TX XBEE   --> RX Arduino (10)
//                      RX XBEE   --> TX Arduino (11)
//                      3v3 XBEE  --> 3.3V Arduino
//                      GND XBEE  --> GND Arduino

const int debit = 9600;
char texte[16];

SoftwareSerial mySerial(10,11); //RX,TX   connectées sur TX,RX du XBEE


void setup() 
{

  Serial.begin(debit);      // liaison RS232 par USB vers le PC  (RX 0  TX 1) pour le moniteur série
  mySerial.begin(debit);    // liaison RS232 par vers le XBEE    (RX 10 TX 11) 

  Serial.println("Test communication RS232 XBEE");

  delay(1000);

}

void loop() 
{

  //if (mySerial.available())
  { 
     Serial.println("25");
      mySerial.write("25\r");
      delay(1000);
    }
  }
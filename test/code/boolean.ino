// importation librairy
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <Wire.h>

// paramétrage

const char buttonPin = A2;
const int debit = 9600; // Débit Tx
char Demarrage;         // Boucle demarrage
char MesureLoop = 0;

int buttonState = 1; // Button définit à l'état 1

void setup()
{
    // Ecran initialisé
    lcd.init();
    lcd.backlight();

    pinMode(buttonPin, INPUT); // Entrée bouton

    delay(1000);
}

void loop()
{

    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Projet BTS");
}
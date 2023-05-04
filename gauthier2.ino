#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const char buttonPin = A2;
int buttonState = 1; // Button définit à l'état 1

void setup()
{
    // Ecran initialisé
    lcd.init();
    lcd.backlight();

    pinMode(buttonPin, INPUT); // Entrée bouton
}

void Measure()
{
    // Lecture de la température à partir du capteur
    Wire.beginTransmission(0x50); // Début de la communication avec le capteur
    Wire.write(0x00);             // Écriture de l'adresse de la température à lire (0x01)
    Wire.endTransmission(false);  // Fin de la transmission en gardant le bus I²C actif
    Wire.requestFrom(0x50, 2);    // Demande de lecture des deux octets de la température mesurée

    if (Wire.available() == 2)
    {                                                // Vérification de la disponibilité des deux octets
        uint8_t msb = Wire.read();                   // Lecture du MSB (Most Significant Byte)
        uint8_t lsb = Wire.read();                   // Lecture du LSB (Least Significant Byte)
        float temperature = (msb << 8 | lsb) / 10.0; // Conversion des deux octets en température
    }

    void loop()
    {
    }
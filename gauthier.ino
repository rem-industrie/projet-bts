#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialisation de l'écran LCD I²C avec l'adresse 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Définition de la broche du buttonPin poussoir
const int buttonPin = 7;
int buttonState = 1; // Button définit à l'état 1

void setup()
{
    Serial.begin(9600); // Initialisation du port série

    lcd.init();      // Initialisation de l'écran LCD
    lcd.backlight(); // Activation du rétroéclairage de l'écran LCD
    lcd.setCursor(0, 0);
    lcd.print("SN IR 0206 I2C");
}

void loop()
{
      buttonState = digitalRead(buttonPin);
    // Vérification si le buttonPin est enfoncé
    if (digitalRead(buttonPin) == LOW)
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

            lcd.setCursor(0, 0);         // Positionnement du curseur sur la première ligne de l'écran LCD
            lcd.print("Temperature:");   // Affichage du texte "Temperature:" sur la première ligne
            lcd.setCursor(0, 1);         // Positionnement du curseur sur la deuxième ligne de l'écran LCD
            lcd.print(temperature);      // Affichage de la température mesurée sur la deuxième ligne
            Serial.println(temperature); // Envoi de la température mesurée sur le port série

            // Envoi des données sur le port série lorsqu'on appuie sur le buttonPin
            if (buttonState == LOW)
            {
                Serial.println(temperature);
                delay(1000); // Attends 1 seconde pour éviter les envois multiples

                delay(100); // Attends 100 ms avant de lire à nouveau le capteur
            }
        }
    }
}
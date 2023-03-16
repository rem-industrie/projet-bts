#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int buttonPin = A2;

int buttonState = 1; // Button définit à l'état 1

void setup()
{
    // Ecran initialisé
    lcd.init();
    lcd.backlight();

    pinMode(buttonPin, INPUT);
}

void loop()
{
    start();

    // Début boucle
}

void start()
{

    // Démarrage système
    lcd.clear();
    lcd.setCursor(0, 0)
        lcd.print("Projet BTS");
    lcd.setCursor(2, 1);
    lcd.print("2023");

    lcd.clear();
    lcd.print("Initialisation");
    lcd.setCursor(0, 1);
    lcd.print("...");
    delay(2000);
    lcd.clear();

    break;
}

void buttonPush();
{
    buttonState = digitalRead(buttonPin);

    //Si etat du boutton === 0 alors il éffectue le code sinon il affiche rien
    if (buttonState == LOW)
    {

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Mesure en cours");

        lcd.setCursor(2, 1);
        lcd.print("...");

        lcd.clear();
        lcd.print("Tension:");
        lcd.setCursor(0, 1);
        lcd.print("Intensité:");
        
    }
}
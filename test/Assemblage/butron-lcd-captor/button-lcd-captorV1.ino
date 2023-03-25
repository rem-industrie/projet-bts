/*
Problème sur le bouton

il ne réagit que vers la fin du delay(2000);
*/

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const char buttonPin = A2;
char Demarrage;      // Boucle demarrage
int buttonState = 1; // Button définit à l'état 1

void setup()
{
    // Ecran initialisé
    lcd.init();
    lcd.backlight();

    pinMode(buttonPin, INPUT);
}

void measureStart()
{

    int adc = analogRead(A0);               // Définit pin de lecture sur le pin Analogique A0
    float voltage = adc * 5 / 1023.0;       // Converti la tension
    float current = (voltage - 2.5) / 0.40; // Converti le courant (Sensibilité 4OmA)

    // Envoie dans la console le courant et tension Toutes les 8s

    // affichage écran
    lcd.clear();
    lcd.print("Tension: ");
    lcd.print(voltage);
    lcd.print("V");

    lcd.setCursor(0, 1);
    lcd.print("Courant: ");
    lcd.print(current);
    lcd.print("A");
}

void measure()
{

    int adc = analogRead(A0);               // Définit pin de lecture sur le pin Analogique A0
    float voltage = adc * 5 / 1023.0;       // Converti la tension
    float current = (voltage - 2.5) / 0.40; // Converti le courant (Sensibilité 4OmA)

    // Envoie dans la console le courant et tension Toutes les 8s

    // affichage écran
    lcd.clear();
    lcd.print("Tension: ");
    lcd.print(voltage);
    lcd.print("V");

    lcd.setCursor(0, 1);
    lcd.print("Courant: ");
    lcd.print(current);
    lcd.print("A");
}

void start()
{

    // Démarrage système
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Projet BTS");

    lcd.setCursor(3, 1);
    lcd.print("2022/2023");

    // Attente de 2s
    delay(2000);

    lcd.clear();
    lcd.print("Initialisation");
    lcd.setCursor(6, 1);

    lcd.print(".");
    delay(1000);
    lcd.print(".");
    delay(1000);
    lcd.print(".");
    delay(1000);

    lcd.clear();
    measureStart();
}

void loop()
{

    if (Demarrage == 0)
    {

        start();
        Demarrage++;
        Serial.print(Demarrage);
    }

    buttonState = digitalRead(buttonPin);

    if (buttonState == LOW)
    {

        lcd.clear();
        lcd.print("Mesure demande");

        lcd.setCursor(0, 1);
        lcd.print("Svp patientez");
        delay(2000);

        measure();
        // Cooldown de 5000s
        delay(5000);
    }
    else
    {
        measure();
        //delay(20000);
    }

    
}

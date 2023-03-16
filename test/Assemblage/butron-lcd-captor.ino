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
    Serial.begin(9600);
}

void loop()
{
    start();


    buttonState = digitalRead(buttonPin);

    //Si l'état du boutton === 0 alors il fais la mesure tout de suite
    if (buttonState == LOW)
    {

        Measure();
    } else {

        Measure();
    }

    delay(10000);

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

void Measure()
{

    lcd.clear();

    int adc = analogRead(A0);               // Définit pin de lecture sur le pin Analogique A0
    float voltage = adc * 5 / 1023.0;       // Converti la tension
    float current = (voltage - 2.5) / 0.40; // Converti le courant (Sensibilité 4OmA)

    // Envoie dans la console le courant et tension Toutes les 8s

    // courant
    lcd.print("Tension: ");
    lcd.print(voltage)
        lcd.setCursor(2, 1);
    lcd.print("Intensité: ");
    lcd.print(current);

    delay(8000);
}
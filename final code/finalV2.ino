// importation librairy
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <Wire.h>

// constante/paramétrage
LiquidCrystal_I2C lcd(0x27, 16, 2);
const char buttonPin = A2;
char Demarrage;                  // Boucle demarrage
int buttonState = 1;             // Button définit à l'état 1
const int debit = 9600;          // Débit Tx
SoftwareSerial mySerial(4,3); // RX,TX redéfinit par la librairy

void setup()
{
    // Ecran initialisé
    lcd.init();
    lcd.backlight();

    pinMode(buttonPin, INPUT); // Entrée bouton

    Serial.begin(debit);
    mySerial.begin(debit);
    Serial.println("Test communication RS232");
    delay(1000);
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

    // Envoie passerelle

    Serial.println("Envoie Courant sur la passerelle");


    mySerial.println(current); //Envoie du courant
    mySerial.println("A-");
    //Console retour test uniquement
    Serial.println(current);

    mySerial.println(voltage); //Envoie du courant
    mySerial.println("V");
    //Console retour test uniquement
    Serial.println(voltage);
    
}

void skip()
{
    buttonState = digitalRead(buttonPin);

    if (buttonState == LOW)
    {
        Demarrage++;
        measure();
        
    }

}

void start()
{

    // Démarrage système
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Projet BTS");

    skip();

    lcd.setCursor(3, 1);
    lcd.print("2022/2023");

     skip();

    // Attente de 2s
    delay(2000);

 skip();
    lcd.clear();
    lcd.print("Initialisation");
    lcd.setCursor(6, 1);

     skip();

    lcd.print(".");
    delay(1000);
     skip();
    lcd.print(".");
    delay(1000);
     skip();
    lcd.print(".");
    delay(1000);

    lcd.clear();
    measure();
}

void loop()
{

    // Si le prototype n'a pas déja affiché le message de départ alors il fait le void start
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
        delay(5000);
    }
}
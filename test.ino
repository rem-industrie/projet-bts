#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <Wire.h>

#define BUTTON_PIN A2;

float defaultSensitivity = 2.50;
float configSensitivity = defaultSensitivity;

void setup() {
  // Configurer le bouton-poussoir en entrée et activer la résistance de tirage
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Initialiser l'affichage I²C
  lcd.init();
  lcd.backlight();

  // Afficher le message de démarrage sur l'écran
  lcd.setCursor(0, 0);
  lcd.print("Systeme demarre");
  lcd.setCursor(0, 1);
  lcd.print("Config en cours...");

  // Attendre 5 secondes pour la configuration
  delay(CONFIG_DURATION);

  // Vérifier si le bouton-poussoir est appuyé
  if (digitalRead(BUTTON_PIN) == LOW) {
    // Si le bouton-poussoir est appuyé, régler la sensibilité à 2,49
    configSensitivity = 2.49;

    // Afficher le message de confirmation sur l'écran
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sensibilite");
    lcd.setCursor(0, 1);
    lcd.print("2.49 enreg.");
  } else {
    // Si le bouton-poussoir n'est pas appuyé, la sensibilité est de 2,50 par défaut
    configSensitivity = defaultSensitivity;

    // Afficher le message de confirmation sur l'écran
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sensibilite");
    lcd.setCursor(0, 1);
    lcd.print("2.50 enreg.");
  }

  // Attendre 1 seconde avant d'afficher le message de fin de configuration
  delay(1000);

  // Afficher le message de fin de configuration sur l'écran
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Fin config");
  delay(1000);
}

void loop() {
  // Le code principal ne fait rien ici
}
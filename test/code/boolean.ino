bool test = false;

void setup() {
  // Initialisation de la broche du bouton en entrée
  pinMode(boutonPin, INPUT_PULLUP);
    pinMode(buttonPin, INPUT); // Entrée bouton
}

void loop() {
  

buttonState = digitalRead(buttonPin);


  if (buttonState == HIGH) {

    Serial.print("Boutton appuyer");
    Serial.print(test);
    test = true;

  } else {

    Serial.print("Relâcher");
    Serial.print(test);
    test = false;
  }

}
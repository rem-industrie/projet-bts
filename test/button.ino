const int buttonPin = 2;

int buttonState = 0;

void setup() {

  pinMode(buttonPin, INPUT);
}

void loop() {

  buttonState = digitalRead(buttonPin);


  if (buttonState == HIGH) {

    Serial.print("Boutton appuyer");

  } else {

    Serial.print("Relâcher");

  }
}
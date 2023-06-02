const char buttonPin = A2;

int buttonState = 1;

void setup() {

  pinMode(buttonPin, INPUT);
}

void loop() {

  buttonState = digitalRead(buttonPin);


  if (buttonState == LOW) {

    Serial.print("Boutton appuyer");

  } else {

    Serial.print("Relâcher");

  }
}
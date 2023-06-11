void setup() {
  Serial.begin(9600);
  Serial.print("Programme lancé").
}

void loop() {

  if (Serial.available()) {

    char caractere = Serial.read();
    

    Serial.print("Caractere recu : ");
    Serial.println(caractere);
    Serial.print("reçu");
  }
}
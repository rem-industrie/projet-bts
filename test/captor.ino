//https://miliohm.com/acs712-current-sensor-arduino/

void setup() {

  Serial.begin(9600);
}
void loop() {

  int adc = analogRead(A0); //Définit pin de lecture sur le pin Analogique A0
  float voltage = adc*5/1023.0; //Converti la tension
  float current = (voltage-2.5)/0.40; //Converti le courant (Sensibilité 4OmA)

  //Envoie dans la console le courant et tension Toutes les 8s

  //Logs courant
  Serial.print("Current : ");
  Serial.println(current);

  //Logs Tension
  Serial.print("Voltage : ");
  Serial.println(voltage);

  delay(8000);
}
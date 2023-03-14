//https://miliohm.com/acs712-current-sensor-arduino/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  int adc = analogRead(A0);
  float voltage = adc*5/1023.0;
  float current = (voltage-2.5)/0.185;
  Serial.print("Current : ");
  Serial.println(current);
  delay(300);
}
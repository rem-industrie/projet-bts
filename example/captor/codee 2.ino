//https://www.instructables.com/ACS724-Current-Sensor-Measurements-With-Arduino/
float V;
float Vav;
int n;


void setup() {
  Serial.begin(9600);
}

void loop() {
for (n=0;n<10;n++) {
V = analogRead(A0) ;
Vav = (Vav + V);
 delay(500);
 Serial.print("V = ");Serial.println(V);

 if (n == 9) {
 Vav = Vav/10;
 Serial.print("Vav = ");Serial.println(Vav);
 Vav = 0;
 }
}

}
int sensorVal = 0;
int sensorHigh = 0;
int sensorLow = 0;
int const ledPin = 13;
void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  while(millis()<5000) {
    sensorVal = analogRead(A0);
    if(sensorVal < sensorLow) {
      sensorLow = sensorVal;
    }
    if (sensorVal > sensorHigh) {
      sensorHigh = sensorVal;
    }
    digitalWrite(ledPin, LOW);
  }
}

void loop() {
  sensorVal = analogRead(A0);
  int pitch = map(sensorVal, sensorLow, sensorHigh, 50, 2500);
  tone(8, pitch, 20);
  delay(10);

}

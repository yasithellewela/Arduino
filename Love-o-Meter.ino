const int sensorPin = A0;
const float defaultTemp = 35.4;

void setup() {
  Serial.begin(9600);
  for (int pinnum = 2; pinnum < 5; pinnum ++){
    pinMode(pinnum, OUTPUT);
    digitalWrite(pinnum, LOW);
  }
  

}

void loop() {
  
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  float voltage = (sensorVal/1024.0)*5.0;
  Serial.print(", Voltage Value: ");
  Serial.print(voltage);

  float temperature = (voltage - 0.5)*100.0;
  Serial.print(", Temperature Value: ");
  Serial.print(temperature);
  Serial.println("C");

  if (temperature < defaultTemp-0.5){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
  }

  else if (temperature >= defaultTemp-0.5 && temperature< defaultTemp + 0.5){
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }

  else if (temperature >= defaultTemp + 0.5){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }

  delay(500);
}

/*
This project reads the temperature of a person's hand, in order to determine whether
they are feeling embarrased or nervous due to a significant other. The temperature values
are mapped to three LEDs: blue, yellow, and red. If the person's hands are cold, the blue LED
will turn on; if it is normal/warm, the yellow LED wil turn on; if it is hot, the red LED will 
turn on.
*/

//initalzing the variables, and setting the temperature of the room to 35.4 degrees.
const int sensorPin = A0;
const float defaultTemp = 35.4;

//begins collecting analog data from the temperature sensor, and initalized the LED pins.
void setup() {
  Serial.begin(9600);
  for (int pinnum = 2; pinnum < 5; pinnum ++){
    pinMode(pinnum, OUTPUT);
    digitalWrite(pinnum, LOW);
  }
  

}

void loop() {
  // Displaying the raw sensor values
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  //convert and display raw sensor values into voltage values
  float voltage = (sensorVal/1024.0)*5.0;
  Serial.print(", Voltage Value: ");
  Serial.print(voltage);
  
  //convert and display voltage values into temperature in degrees celsius
  float temperature = (voltage - 0.5)*100.0;
  Serial.print(", Temperature Value: ");
  Serial.print(temperature);
  Serial.println("C");

  //turns on the blue LED if the sensor reads a "cold" value
  if (temperature < defaultTemp-0.5){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
  }
  //turns on the yellow LED if the sensor reads a "warm or normal" value
  else if (temperature >= defaultTemp-0.5 && temperature< defaultTemp + 0.5){
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  //turns on the red LED if the senor reads a "hot" value
  else if (temperature >= defaultTemp + 0.5){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  //allows for a sustained change, for better user experience
  delay(500);
}

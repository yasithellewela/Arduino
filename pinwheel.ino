/*
This program turns on a dc motor whenever I hold a button switch down. When i release
the button, the motor stops as well. The motor is attached to a pinwheel, for better
user experience.
*/

//Initalized the variables and pins controlling the motor, and receiving digital data from the button
const int switchPin = 2;
const int motorPin = 9;
int switchState = 0;
void setup() {
  pinMode(switchPin, INPUT);
  pinMode(motorPin, OUTPUT);

}

void loop() {
  //reads the state of the button switch (high or low)
  switchState = digitalRead(switchPin);

  //if the button is clicked, the motor will start
  if(switchState == HIGH){
    digitalWrite(motorPin, HIGH);
  }
  //if the button is not currently being clicked(held down) the motor is idle.
  else{
    digitalWrite(motorPin, LOW);
  }

}

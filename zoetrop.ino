/*
This program builds on the original pinwheel project, in a much more advanced way.
It utlizies two switches, one to indicate whether the motor should be spining or not,
and the other to indicate which direction to spin. Aditionally a potentiometer is used
to indicate the speed of the motor. By using a bit of craftsmans ship, I can create an 
animation by spining the content of a paper really quickly. This project also utilizes a
integrated circuit for more efficient functionality.
*/

//iniatlized the two switches and the potentiometer pin, along with variables.
const int controlpin1 = 2;
const int controlpin2 = 3;
const int onoff = 5;
const int directionSwitch = 4;
const int enablePin = 9;
const int potPin = A0;

int onoffState = 0;
int ponoffState = 0;
int directionState = 0;
int pdirectionState = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

void setup() {
  //sets the control pins to the integrated circuit, for speed and direction as outputs.
  pinMode(controlpin1, OUTPUT);
  pinMode(controlpin2, OUTPUT);

  //sets on-off and direction buttons as inputs
  pinMode(onoff, INPUT);
  pinMode(directionSwitch, INPUT);

  //sets the enable pin, acting as the on-off for the intergrated circuit as an output
  pinMode(enablePin, OUTPUT);

  //We want to turn the enable pin off, so the motor doesnt start as soon as we power the Arduino.
  digitalWrite(enablePin, LOW);

}

void loop() {
  //checks the state of the on-off button
  onoffState = digitalRead(onoff);

  //check the state of the direction button
  directionState = digitalRead(directionSwitch);

  //converts the potentiometer value into a motorspeed value
  motorSpeed = analogRead(potPin)/4;

  /*
  If the state of the on-off switch was not what it was before, then change the state
  of the motor to the opposite of what it is currently doing. Thus, if the switch is clicked
  and the motor was off, turn the motor on; if the motor was on, then turn the motor off. The
  same logic applies to the direction switch and if statements.
  */
  if (onoffState!=ponoffState){
    if(onoffState == HIGH){
      motorEnabled = !motorEnabled;
    }
  }
  if (directionState !=pdirectionState){
    if(directionState == HIGH){
      motorDirection = !motorDirection;
    }
  }
  //If the value of the motor direction is 1, then spin the motor one way.
  if (motorDirection == 1){
    digitalWrite(controlpin1, HIGH);
    digitalWrite(controlpin2, LOW);
    
  }
  //If the value of the motor direciton isn't 1, then spind the motor in the opposite direction
  else{
    digitalWrite(controlpin1, LOW);
    digitalWrite(controlpin2, HIGH);
  }
  //if we want the motor on, then the motor turns on, at the speed which we give it
  if (motorEnabled == 1){
    analogWrite(enablePin, motorSpeed);
    
  }
  //if not then it remains off
  else{
    analogWrite(enablePin, 0);
  }

  //since the on-off and direction switches work by detecting a change, we always reset the value of the swtich
  ponoffState = onoffState;
  pdirectionState = directionState;

}

/*
This program utilizes two componets: a servo motor, which is a motor that only
rotates 180 degrees, and a potentiometer, which is basically a variable resistor
that outputs a voltage dependant on how much you turn a knob. When turning the knob,
the program will convert the voltage output into the state of the servo motor, which
will allow us to control the servo motor using the potentiometer. This can allow us to
indicate, using a bit of paper and craft, whether we want people to enter our room or not,
depending on our mood, hence the name mood cue.
*/

//Use the servo library in the Ardunio IDE
#include <Servo.h>
//Iniatalize an object to be used
Servo myServo;
//Iniaztlize the variables and pins needed.
int const pinPot = A0;
int pinVal = 0;
int angle = 0;

//Begin receiving analog data and indicate which pin we connected the servo motor to
void setup() {
  myServo.attach(9);
  Serial.begin(9600);
 
}

void loop() {
  //Read the potentiometer voltage
  pinVal = analogRead(pinPot);

  //Display value for the user
  Serial.print("Pin Value = ");
  Serial.print(pinVal);

  //Map the value to a angle value to be used by the servo motor
  angle = map(pinVal, 5, 1023, 0, 175);

  //Display the angle vaue to the user
  Serial.print(", Angle Value = ");
  Serial.println(angle);

  //Turn the servo motor to the desired angle
  myServo.write(angle);

  //Include a delay in order to better the user experience
  delay(5);

}

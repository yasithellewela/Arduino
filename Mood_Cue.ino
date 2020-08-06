#include <Servo.h>
Servo myServo;
int const pinPot = A0;
int pinVal = 0;
int angle = 0;

void setup() {
  myServo.attach(9);
  Serial.begin(9600);
 
}

void loop() {
  pinVal = analogRead(pinPot);
  Serial.print("Pin Value = ");
  Serial.print(pinVal);

  angle = map(pinVal, 5, 1023, 0, 175);
  Serial.print(", Angle Value = ");
  Serial.println(angle);

  myServo.write(angle);
  delay(5);

}

/*
This is a simple program that changes the state of three LEDs when a button is clicked,
to simulate the arm or disarm of a weapon on a spaceship in a Sci-fi movie.
*/

//iniatlizing the switch variable has off
int switchState = 0;

//iniatlzing the led pins as outputs, and the button pin as an input.
void setup() {
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, INPUT);

}

void loop() {
  //reads the state of the button
  switchState = digitalRead(2);

  /*
  The following code creates a flashing pattern of the three LEDs when the 
  button is held down, and when its not held down, one LED remains on, without
  flashing. The pattern is insignificant, and can be changed in any way. Delays
  are included so the user can see a sustained difference.
  */
  if (switchState == LOW) {
      digitalWrite(5, LOW);
      digitalWrite(4, LOW);
      digitalWrite(3, HIGH);
  }
  else {
      digitalWrite(5, LOW);
      digitalWrite(4, LOW);
      digitalWrite(3, LOW);

      delay(250);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      delay(250);
  }
   

}

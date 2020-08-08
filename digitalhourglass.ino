/*
This project uses the orinetation of a tilt sensor to reset a "hourglass", whose
time elapse can be shown using a series of LEDs. When the orientation of the tilt
sensor is changed, the LED's are all reset, and then begin to restart the count.
*/

//initalize variables
const int switchPin = 8;

unsigned long previousTime = 0;

int switchState = 0;
int pswitchState = 0;
float gap = 1666.666666667;
int led = 2;

//initalizing Arduino pins as output to LEDs(5 of them).
void setup() {
  for (int x = 2; x < 8 ; x++){
    pinMode(x, OUTPUT);
  }
  //initalizing this pin as an input from the tilt sensor.
  pinMode(switchPin, INPUT);

}

void loop() {
  //starts counting elapsed time
  unsigned long currentTime = millis();
  /*
  This program works, by dividing the total time we want to elapse on the timer, 
  into increments. When each increment is reached, a LED will turn on to indicate
  the progress. This increment is given the "gap" variable. The subtraction between
  current time and previous time tells us when the increment is reached.
  */
  if (currentTime - previousTime > gap){
    previousTime = currentTime;
    digitalWrite(led, HIGH);
    led ++;
    }
  /*
  When the final LED has lit up, which marks the end of the hourglass, this code
  will write a series of flashes which indicates to the user that the desired elapsed time
  has been reached
  */
   if (led ==8){
    delay(500);
    for(int y = 1; y<9; y++){
      for(int x=2; x<8; x++){
        digitalWrite(x, LOW);
      }
      delay(100);
      for(int x=2; x<8; x++){
        digitalWrite(x, HIGH);
      }
    }
   }
   //if the tilt sensor is activated, the timer resets, along with the LEDs.
   switchState = digitalRead(switchPin);
   if (switchState!=pswitchState){
    for(int x=2; x<8; x++){
      digitalWrite(x, LOW);
      led = 2;
      previousTime = currentTime;
      pswitchState = switchState;
    }
  }

}

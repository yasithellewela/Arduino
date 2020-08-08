  /*
  This project uses phototransistors, with gels on top of it to only allow specific wavelength of light to be absorbed,
  in order to detect how much light there is in the room. While doing so, we use a common cathode RGB LED to display the color whose
  phototransistor is recieving the most light. This is the code that reads the phototranistor values, and writes the data to the RGB LED.
  */
  
  //Initalization of variables
  const int greenpin = 10;
  const int bluepin = 11;
  const int redpin = 12;

  const int redsens = A0;
  const int bluesens = A1;
  const int greensens = A2;

  int greenval = 0;
  int blueval = 0;
  int redval = 0;

  int redsensval = 0;
  int bluesensval = 0;
  int greensensval = 0;

//begin receiving analog data.
void setup() {
  
  Serial.begin(9600);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(redpin, OUTPUT);
  
}

void loop() {
  //reads the inital value of the sensors
  redsensval = analogRead(redsens); 
  delay(5);
  bluesensval= analogRead(bluesens);
  delay(5);
  greensensval = analogRead(greensens);

  //map values to a number that can be used by the LED
  greenval = greensensval / 4;
  redval = redsensval / 4;
  blueval = bluesensval / 4;

  //User display
  Serial.print("Raw Sensor Values \t Red: ");
  Serial.print(redsensval);
  Serial.print("\t Green: ");
  Serial.print(greensensval);
  Serial.print("\t Blue: ");
  Serial.println(bluesensval);

  Serial.print("Mapped Sensor Values \t Red: ");
  Serial.print(redval);
  Serial.print("\t Green: ");
  Serial.print(greenval);
  Serial.print("\t Blue: ");
  Serial.println(blueval);

  //writes the values to the LED
  analogWrite(greenpin, greenval);
  analogWrite(redpin, redval);
  analogWrite(bluepin, blueval);

  //allows for sustained color changes
  delay(1000);
}

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
void setup() {
  
  Serial.begin(9600);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(redpin, OUTPUT);
  
}

void loop() {
  redsensval = analogRead(redsens);
  delay(5);
  bluesensval= analogRead(bluesens);
  delay(5);
  greensensval = analogRead(greensens);

  greenval = greensensval / 4;
  redval = redsensval / 4;
  blueval = bluesensval / 4;

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

  analogWrite(greenpin, greenval);
  analogWrite(redpin, redval);
  analogWrite(bluepin, blueval);

  delay(1000);
}

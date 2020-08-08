/*
This project uses a piezo, which emits a frequency of sound depending on how much
light an adjacent phototransisotr absorbs. By waving my hand over the phototrasnsitor,
i can change the frequency of the sound the piezo emits, which results in a cool effect.
*/

//Initalizing variables
int sensorVal = 0;
int sensorHigh = 0;
int sensorLow = 0;
int const ledPin = 13;

//This calibrates the phototransitor values, as I wave my hand, without the piezo making sounds.
void setup() {
  //indicates that the program is calibrating the phototransistor
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  
  //calibrate for 5 seconds
  while(millis()<5000) {
    sensorVal = analogRead(A0);
    if(sensorVal < sensorLow) {
      sensorLow = sensorVal;
    }
    if (sensorVal > sensorHigh) {
      sensorHigh = sensorVal;
    }
    //Indicates to the user that calibration is complete
    digitalWrite(ledPin, LOW);
  }
}

void loop() {
  //Reads the values from the phototransistor
  sensorVal = analogRead(A0);

  //maps the phototransistor values to a pitch that the piezo can emit
  int pitch = map(sensorVal, sensorLow, sensorHigh, 50, 2500);

  /*
  The tone argument takes three arguments: which pin the piezo is connected to,
  which pitch to play, and how long to play the pitch for(in milliseconds)
  */
  tone(8, pitch, 20);
  delay(10);

}

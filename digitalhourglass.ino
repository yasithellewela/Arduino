const int switchPin = 8;

unsigned long previousTime = 0;

int switchState = 0;
int pswitchState = 0;
float gap = 1666.666666667;
int led = 2;

void setup() {
  for (int x = 2; x < 8 ; x++){
    pinMode(x, OUTPUT);
  }
  pinMode(switchPin, INPUT);

}

void loop() {
  unsigned long currentTime = millis();
  if (currentTime - previousTime > gap){
    previousTime = currentTime;
    digitalWrite(led, HIGH);
    led ++;
    }
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

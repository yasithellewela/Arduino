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

while pdirectionState 

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

void setup() {
  pinMode(controlpin1, OUTPUT);
  pinMode(controlpin2, OUTPUT);
  pinMode(onoff, INPUT);
  pinMode(directionSwitch, INPUT);
  pinMode(enablePin, OUTPUT);

  digitalWrite(enablePin, LOW);

}

void loop() {
  onoffState = digitalRead(onoff);
  directionState = digitalRead(directionSwitch);
  motorSpeed = analogRead(potPin)/4;
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
  if (motorDirection == 1){
    digitalWrite(controlpin1, HIGH);
    digitalWrite(controlpin2, LOW);
    
  }
  else{
    digitalWrite(controlpin1, LOW);
    digitalWrite(controlpin2, HIGH);
  }

  if (motorEnabled == 1){
    analogWrite(enablePin, motorSpeed);
    
  }
  else{
    analogWrite(enablePin, 0);
  }

  ponoffState = onoffState;
  pdirectionState = directionState;

}

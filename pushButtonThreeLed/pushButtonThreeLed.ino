const int redButtonPin = 2;
const int greenButtonPin = 3;
const int yellowButtonPin = 4;

const int redLedPin = 13;
const int greenLedPin = 12;
const int yellowLedPin = 11;

int redButtonState = 0;
int greenButtonState = 0;
int yellowButtonState = 0;

void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  
  pinMode(redButtonPin, INPUT);
  pinMode(yellowButtonPin, INPUT);
  pinMode(greenButtonPin, INPUT);
}

void loop() {
  redButtonState = digitalRead(redButtonPin);
  greenButtonState = digitalRead(greenButtonPin);
  yellowButtonState = digitalRead(yellowButtonPin);

  if(redButtonState == HIGH) {
    digitalWrite(redLedPin, HIGH);
  } 
  else {
    digitalWrite(redLedPin, LOW);
  }
  
  if(greenButtonState == HIGH) {
    digitalWrite(greenLedPin, HIGH);
  } 
  else {
    digitalWrite(greenLedPin, LOW);
  }
  
  if(yellowButtonState == HIGH) {
    digitalWrite(yellowLedPin, HIGH);
  } 
  else {
    digitalWrite(yellowLedPin, LOW);
  }
}


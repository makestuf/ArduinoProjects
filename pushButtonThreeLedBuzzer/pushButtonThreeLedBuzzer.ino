const int redButtonPin = 2;
const int greenButtonPin = 3;
const int yellowButtonPin = 4;

const int redLedPin = 13;
const int greenLedPin = 12;
const int yellowLedPin = 11;

const int buzzerPin = 10;

int redButtonState = 0;
int greenButtonState = 0;
int yellowButtonState = 0;
int buzzerTone = 0;

void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  
  pinMode(redButtonPin, INPUT);
  pinMode(yellowButtonPin, INPUT);
  pinMode(greenButtonPin, INPUT);
  
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  redButtonState = digitalRead(redButtonPin);
  greenButtonState = digitalRead(greenButtonPin);
  yellowButtonState = digitalRead(yellowButtonPin);
  
  buzzerTone = 0;

  if(redButtonState == HIGH) {
    digitalWrite(redLedPin, HIGH);
    buzzerTone += 100;
  } 
  else {
    digitalWrite(redLedPin, LOW);
    //buzzerTone -= 100;
  }
  
  if(greenButtonState == HIGH) {
    digitalWrite(greenLedPin, HIGH);
    buzzerTone += 200;
  } 
  else {
    digitalWrite(greenLedPin, LOW);
    //buzzerTone -= 200;
  }
  
  if(yellowButtonState == HIGH) {
    digitalWrite(yellowLedPin, HIGH);
    buzzerTone += 500;
  } 
  else {
    digitalWrite(yellowLedPin, LOW);
    //buzzerTone -= 500;
  }
  
  if(buzzerTone > 0) {
    digitalWrite(buzzerPin, HIGH);
    delayMicroseconds(buzzerTone);
    digitalWrite(buzzerPin, LOW);
    delayMicroseconds(buzzerTone);
  } else {
    digitalWrite(buzzerPin, LOW);
  }
}


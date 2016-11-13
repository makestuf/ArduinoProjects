const int buttonPin = 2;    //Push button
const int ledPin = 13;      // Led Pin
int buttonState = 0;        //0 or 1 (LOW or HIGHT), for read State

void setup() {
  pinMode(ledPin, OUTPUT);    //LED: SET state
  pinMode(buttonPin, INPUT);  //Button: READ state
}

void loop() {
  buttonState = digitalRead(buttonPin);   //Read button state

  //If is pressed
  if(buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
  } 
  else {
    digitalWrite(ledPin, LOW);
  }
}


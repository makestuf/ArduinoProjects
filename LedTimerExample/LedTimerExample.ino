//Seta pinos
const int redLedPin = 13;
const int greenLedPin = 12;
const int yellowLedPin = 11;

//Estados
int redLedState = LOW;

long previousMillis = 0;
long interval = 1000;

void setup()
{
	pinMode(redLedPin, OUTPUT);
	pinMode(greenLedPin, OUTPUT);
	pinMode(yellowLedPin, OUTPUT);
}

void loop()
{
	unsigned long currentMillis = millis();

	if (currentMillis - previousMillis > interval) {
		previousMillis = currentMillis;

		if (redLedState == LOW)
			redLedState = HIGH;
		else
			redLedState = LOW;

		digitalWrite(redLedPin, redLedState);
	}

	

}

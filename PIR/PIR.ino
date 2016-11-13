int pirPin = 2; //digital 2
int LedPin = 13;

void setup(){
	Serial.begin(9600);
	pinMode(pirPin, INPUT);
	pinMode(LedPin, OUTPUT);
}
void loop(){
	int pirVal = digitalRead(pirPin);

	Serial.println(pirVal);

	if (pirVal == LOW){ //was motion detected
		digitalWrite(LedPin, HIGH);
		delay(300);
	}
	else
	{
		digitalWrite(LedPin, LOW);
	}
}
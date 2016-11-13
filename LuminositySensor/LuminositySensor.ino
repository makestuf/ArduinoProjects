const int LedPin = 11;			//Pino digital onde est� o LED
const int LuminosityPin = A0;	//Pino anal�gico onde est� o terminal do sensor
const int FlashLedPin = 13;

int LuminosityValue;
int PWM;
int MaxLuminosity = 220;

void setup()
{
	Serial.begin(9600);			//Porta serial para debugar o c�digo
	pinMode(LedPin, OUTPUT);	//Modo do pino do LED
	pinMode(FlashLedPin, OUTPUT);
}

void loop()
{
	//Valor de entrada do sensor. Lembrando que temos uma resolu��o de entrada de 10bits, 
	//logo este valor ir� variar de 0 a 1023.
	LuminosityValue = analogRead(LuminosityPin);
	
	if (LuminosityValue > MaxLuminosity) {
		LuminosityValue = MaxLuminosity;
	}

	//Mapeamento dos valores m�nimo e m�ximo, a fim de usar a Modula��o de Largura de Pulso 
	//(300 � o m�ximo que o sensor atingiu no ambiente de testes, fa�a um teste antes para 
	//verificar a luminosidade m�xima do seu ambiente.)
	PWM = map(LuminosityValue ,0, MaxLuminosity, 0, 255);

	//Escreve o PWM no pin do LED
	analogWrite(LedPin, PWM);

	if (PWM < 100) {
		digitalWrite(FlashLedPin, HIGH);
	}
	else {
		digitalWrite(FlashLedPin, LOW);
	}

	Serial.print("Valor: ");
	Serial.println(LuminosityValue);
}

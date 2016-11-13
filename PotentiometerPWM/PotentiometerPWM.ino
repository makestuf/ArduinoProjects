const int LedPin = 11;		//Pino digital onde est� o LED
const int PotPin = A0;		//Pino anal�gico onde est� o terminal do potenci�metro 

void setup()
{
	pinMode(LedPin, OUTPUT);	//Modo do pino do LED
}

void loop()
{
	//Valor de entrada do potenci�metro. Lembrando que temos uma resolu��o de entrada de 10bits, 
	//logo este valor ir� variar de 0 a 1023.
	int PotValue = analogRead(PotPin);

	//Mapeamento dos valores m�nimos e m�ximos. Os seguintes par�metros s�o passados:
	//1. O valor a ser convertido
	//2. O valor m�nimo do pino anal�gico (0)
	//3. O valor m�ximo do pino anal�gico (1023)
	//4. O valor m�nimo desejado (0)
	//5. O valor m�ximo desejado (255)
	int PWM = map(PotValue, 0, 1023, 0, 255);

	//Instrui o Ardu�no passando o valor do PWM
	analogWrite(LedPin, PWM);

}

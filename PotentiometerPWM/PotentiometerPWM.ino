const int LedPin = 11;		//Pino digital onde está o LED
const int PotPin = A0;		//Pino analógico onde está o terminal do potenciômetro 

void setup()
{
	pinMode(LedPin, OUTPUT);	//Modo do pino do LED
}

void loop()
{
	//Valor de entrada do potenciômetro. Lembrando que temos uma resolução de entrada de 10bits, 
	//logo este valor irá variar de 0 a 1023.
	int PotValue = analogRead(PotPin);

	//Mapeamento dos valores mínimos e máximos. Os seguintes parâmetros são passados:
	//1. O valor a ser convertido
	//2. O valor mínimo do pino analógico (0)
	//3. O valor máximo do pino analógico (1023)
	//4. O valor mínimo desejado (0)
	//5. O valor máximo desejado (255)
	int PWM = map(PotValue, 0, 1023, 0, 255);

	//Instrui o Arduíno passando o valor do PWM
	analogWrite(LedPin, PWM);

}

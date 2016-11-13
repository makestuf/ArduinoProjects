const int LedPin = 13;		//Pino digital onde est� o LED
const int PotPin = A0;		//Pino anal�gico onde est� o terminal do potenci�metro 

void setup()
{
	Serial.begin(9600);			//Porta serial para debugar o c�digo
	pinMode(LedPin, OUTPUT);	//Modo do pino do LED
}

void loop()
{
	//Valor de entrada do potenci�metro. Lembrando que temos uma resolu��o de entrada de 10bits, 
	//logo este valor ir� variar de 0 a 1023.
	int PotValue = analogRead(PotPin);

	digitalWrite(LedPin, HIGH);			//Liga o LED	
	
	//Tempo de espera at� desligar o LED. Aqui usaremos diretamente o valor do potenci�metro,
	//o que indica que o LED ficar� ligado caso o valor seja 0 e piscar� (aproximadamnente) 
	//a cada 1 segundo (ou 1023 milisegundos)
	delay(PotValue);

	digitalWrite(LedPin, LOW);			//Deliga o LED

	//Novamente o delay, agora para ligar o LED
	delay(PotValue);

	//Mostra na porta serial o valor do potenci�metro
	Serial.print("Valor: ");
	Serial.println(PotValue);
}

const int LedPin = 13;		//Pino digital onde está o LED
const int PotPin = A0;		//Pino analógico onde está o terminal do potenciômetro 

void setup()
{
	Serial.begin(9600);			//Porta serial para debugar o código
	pinMode(LedPin, OUTPUT);	//Modo do pino do LED
}

void loop()
{
	//Valor de entrada do potenciômetro. Lembrando que temos uma resolução de entrada de 10bits, 
	//logo este valor irá variar de 0 a 1023.
	int PotValue = analogRead(PotPin);

	digitalWrite(LedPin, HIGH);			//Liga o LED	
	
	//Tempo de espera até desligar o LED. Aqui usaremos diretamente o valor do potenciômetro,
	//o que indica que o LED ficará ligado caso o valor seja 0 e piscará (aproximadamnente) 
	//a cada 1 segundo (ou 1023 milisegundos)
	delay(PotValue);

	digitalWrite(LedPin, LOW);			//Deliga o LED

	//Novamente o delay, agora para ligar o LED
	delay(PotValue);

	//Mostra na porta serial o valor do potenciômetro
	Serial.print("Valor: ");
	Serial.println(PotValue);
}

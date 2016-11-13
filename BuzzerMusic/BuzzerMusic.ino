//Seta pinos
const int buzzerPin = 10;
const int redLedPin = 13;
const int greenLedPin = 12;
const int yellowLedPin = 11;

//Estados
int redButtonState = 0;
int greenButtonState = 0;
int yellowButtonState = 0;

//Temporizador
int savedTime= 0;
int melodyStep = 0;

//Notas
#define DO 261
#define RE 294
#define MI 329
#define FA 349
#define SOL 392
#define LA 440
#define SI 493

//Melodias
int melody1[] =			{DO,  RE,  MI,  FA,  FA,  FA,  DO,  RE,  DO,  RE,  RE,  RE,  DO,  SOL, FA,  MI,  MI,  MI,  DO,  RE,  MI,  FA,  FA,  FA};
int melody1Time[] =		{200, 200, 200, 300, 200, 200, 200, 200, 200, 300, 200, 200, 200, 200, 200, 300, 200, 200, 200, 200, 200, 300, 200, 300};
int melody1Delay[] =	{200, 200, 200, 350, 200, 350, 200, 200, 200, 350, 200, 350, 200, 200, 200, 350, 200, 350, 200, 200, 200, 350, 200, 200};

void setup() {
	//Modo de cada pino
	pinMode(buzzerPin, OUTPUT);

	pinMode(redLedPin, OUTPUT);
	pinMode(greenLedPin, OUTPUT);
	pinMode(yellowLedPin, OUTPUT);
}

void loop() {
	unsigned int seekTime = millis();

	//Em C, não existe um função para calcular a quantidade de itens de um array.
	//O sizeof calcula o tamanho em bits do array. 
	//Então podemos calcular da seguinte forma: sizeof(meuArray) / sizeof(char *)

	if ((melodyStep < sizeof(melody1) / sizeof(char *)) && (seekTime - savedTime > melody1Delay[melodyStep - 1])) {

		//Acende as leds
		switch (melody1[melodyStep])
		{
		case DO:
			digitalWrite(redLedPin, HIGH);
			break;
		case RE:
			digitalWrite(greenLedPin, HIGH);
			break;
		case MI:
			digitalWrite(yellowLedPin, HIGH);
			break;
		case FA:
			digitalWrite(redLedPin, HIGH);
			digitalWrite(greenLedPin, HIGH);
			digitalWrite(yellowLedPin, HIGH);
			break;
		case SOL:
			digitalWrite(redLedPin, HIGH);
			digitalWrite(greenLedPin, HIGH);
			break;
		}

		//Toca o som
		tone(buzzerPin, melody1[melodyStep], melody1Time[melodyStep]);

		//Desliga LEDs
		digitalWrite(redLedPin, LOW);
		digitalWrite(greenLedPin, LOW);
		digitalWrite(yellowLedPin, LOW);

		//Salva o tempo e o step
		savedTime = seekTime;
		melodyStep++;

	}

}
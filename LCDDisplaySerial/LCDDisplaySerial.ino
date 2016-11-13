//Inclui a biblioteca LiquidCrystal para facilitar a manipulação do display
#include <LiquidCrystal\LiquidCrystal.h>

//Cria instância do display, informando os pinos utilizados
LiquidCrystal LCD(12, 11, 5, 4, 3, 2);

//Variáveis para receber do SERIAL
int serialMessageByte;
int count = 0;
int countSerial = 0;
int verify = 0;
int x = 0;

void setup()
{
	//Informa quantidade de colunas e a quantidade de linhas do LCD
	LCD.begin(16, 2);

	//Para debugar
	Serial.begin(9600);
}

void loop()
{
	//Verifica se ocorreu algum comando na porta serial
	if (Serial.available()) {
		if (verify == 0) {
			LCD.clear();
			LCD.setCursor(0, 0);
		}

		//Lê o valor enviado pela porta serial
		serialMessageByte = Serial.read();

		//Escreve o caractere recebido (usamos char para converter o código ASCII em caractere)
		LCD.print(char(serialMessageByte));

		//Verifica a coluna
		x++;
		if (x == 16) {
			LCD.setCursor(0, 2);
		}

		delay(50);

		count++;
		countSerial = count + 1;
		verify = 1;
	}

	count++;

	//Terminou de escrever
	if (count > countSerial) {
		verify = 0;
		count = 0;
		x = 0;
		countSerial = 0;
	}
}

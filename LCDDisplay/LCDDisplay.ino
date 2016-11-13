//Inclui a biblioteca LiquidCrystal para facilitar a manipulação do display
#include <LiquidCrystal\LiquidCrystal.h>

//Cria instância do display, informando os pinos utilizados
LiquidCrystal LCD(12, 11,5,4,3,2);

void setup()
{
	//Informa qualidade de colunas e a quantidade de linhas do LCD
	LCD.begin(16, 2);

	
}

void loop()
{
	//Informa a posição inicial da escrita
	LCD.setCursor(0, 0);

	//Imprime uma mensagem
	LCD.clear();
	LCD.print("My name is:");
	LCD.setCursor(0, 1);
	LCD.print("Rafael Heringer");

	//Aguarda 2 segundos
	delay(2000);

	//Imprime outra mensagem
	LCD.clear();
	LCD.setCursor(0, 0);
	LCD.print("Hello Word");
	LCD.setCursor(0, 1);
	LCD.print("-----------");


	//Aguarda 2 segundos
	delay(2000);
}

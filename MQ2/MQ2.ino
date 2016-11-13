/*
 O MQ2 j� com circuito integrado possui 4 pinos:
 GND - Ground
 VCC - Entrava 5V
 A0  - Sa�da anal�gica
 D0  - Sa�da digital

 O potenci�metro do circuito serve para controlar a sensibilidade do sensor para a sa�da digital.
*/

//Configura��es
int mqSensorPin = A2;
int gasConcentration;
int gasPPM;

void setup()
{
	//Abre porta
	Serial.begin(9600);

	//Define tipo de entrada/saida
	pinMode(mqSensorPin, INPUT);
}

void loop()
{
	//L� o valor
	int mqSensorValue = analogRead(mqSensorPin);

	//Mapeamento dos valores m�nimo e m�ximo, a fim de usar a Modula��o de Largura de Pulso 
	//Propano: 200 - 5000ppm
	//Butano: 300 - 5000ppm
	//Metano: 5000 - 20000ppm
	//Hidrogenio: 300 - 5000ppm
	//Alcool: 100 - 2000ppm
	//Fa�a o teste de base para verificar o m�nimo de PPM do g�s desejado
	//0 � o m�nimo de sa�da do pino e 1023 sempre ser� o m�ximo do Arduino
	gasConcentration = map(mqSensorValue, 0, 1023, 0, 100);
	gasPPM = map(mqSensorValue, 0, 1023, 5000, 20000);

	Serial.print("Valor: ");
	Serial.println(mqSensorValue);
	Serial.print("Percentual: ");
	Serial.println(gasConcentration);
	Serial.print("Concentracao: ");
	Serial.println(gasPPM);

	delay(3000);
}
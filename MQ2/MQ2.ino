/*
 O MQ2 já com circuito integrado possui 4 pinos:
 GND - Ground
 VCC - Entrava 5V
 A0  - Saída analógica
 D0  - Saída digital

 O potenciômetro do circuito serve para controlar a sensibilidade do sensor para a saída digital.
*/

//Configurações
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
	//Lê o valor
	int mqSensorValue = analogRead(mqSensorPin);

	//Mapeamento dos valores mínimo e máximo, a fim de usar a Modulação de Largura de Pulso 
	//Propano: 200 - 5000ppm
	//Butano: 300 - 5000ppm
	//Metano: 5000 - 20000ppm
	//Hidrogenio: 300 - 5000ppm
	//Alcool: 100 - 2000ppm
	//Faça o teste de base para verificar o mínimo de PPM do gás desejado
	//0 é o mínimo de saída do pino e 1023 sempre será o máximo do Arduino
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
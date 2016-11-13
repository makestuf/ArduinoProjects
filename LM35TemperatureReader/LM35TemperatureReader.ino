//Vari�veis
const int sensorAnPin = 0;

const int maxVoltage = 1.1 * 1000;						//1.1 se aplicado INTERNAL (em microvolts) e 5 normalmente
const int voltagePerCelsius = 10;						//Quantos microvolts por grau celsius o sensor retorna
const float maxReaderSize = pow(2, 10) - 1;				//10bits = 1024 (-1)

const int maxSensorTemperature = 110;												//Temperatura m�xima do sensor (110�C para 1.1V e 150�C para > 1.5V)
const int maxSensorVoltage = maxSensorTemperature * voltagePerCelsius;				//M�xima voltagem que o sensor ir� descarregar (m�x de 150�C)
const float maxSensorReaderSize = (maxSensorVoltage * maxReaderSize) / maxVoltage;	//M�ximo de leitura que o sensor vai retornar

//Readers
float temperature = 0;
float  sensorVoltage = 0;

void setup()
{
	//Leitura SERIAL
	Serial.begin(9600);
	analogReference(INTERNAL);	//Limita a entra anal�gica para 1.1V
}

void loop()
{
	//Busca resultado do ADC
	unsigned int sensorADC = analogRead(sensorAnPin);

	//Converte a leitura em temperatura (convers�o direta regra de tr�s)
	//temperature = (maxSensorTemperature / maxReaderSize) * sensorADC;

	//Converte a leitura em tens�o
	sensorVoltage = (maxSensorVoltage / maxReaderSize) * sensorADC;

	//Converte a tens�o em temperatura
	temperature = (sensorVoltage / voltagePerCelsius);

	//DEBUGs
	Serial.print("maxSensorReaderSize: ");
	Serial.println(maxSensorReaderSize);

	Serial.print("sensorADC: ");
	Serial.println(sensorADC);
	
	Serial.print("sensorVoltage: ");
	Serial.println(sensorVoltage);

	Serial.print("Temperatura: ");
	Serial.println(temperature);


}

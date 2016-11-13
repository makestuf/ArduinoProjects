//Variáveis
const int sensorAnPin = 0;

const int maxVoltage = 1.1 * 1000;						//1.1 se aplicado INTERNAL (em microvolts) e 5 normalmente
const int voltagePerCelsius = 10;						//Quantos microvolts por grau celsius o sensor retorna
const float maxReaderSize = pow(2, 10) - 1;				//10bits = 1024 (-1)

const int maxSensorTemperature = 110;												//Temperatura máxima do sensor (110ºC para 1.1V e 150ºC para > 1.5V)
const int maxSensorVoltage = maxSensorTemperature * voltagePerCelsius;				//Máxima voltagem que o sensor irá descarregar (máx de 150ºC)
const float maxSensorReaderSize = (maxSensorVoltage * maxReaderSize) / maxVoltage;	//Máximo de leitura que o sensor vai retornar

//Readers
float temperature = 0;
float  sensorVoltage = 0;

void setup()
{
	//Leitura SERIAL
	Serial.begin(9600);
	analogReference(INTERNAL);	//Limita a entra analógica para 1.1V
}

void loop()
{
	//Busca resultado do ADC
	unsigned int sensorADC = analogRead(sensorAnPin);

	//Converte a leitura em temperatura (conversão direta regra de três)
	//temperature = (maxSensorTemperature / maxReaderSize) * sensorADC;

	//Converte a leitura em tensão
	sensorVoltage = (maxSensorVoltage / maxReaderSize) * sensorADC;

	//Converte a tensão em temperatura
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

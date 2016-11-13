#include<math.h>

//Variáveis do sensor de temperatura
const int sensorAnPin = 0;
const float maxReaderSize = pow(2, 10) - 1;		//10bits = 1024 (-1)
const int maxSensorTemperature = 110;			//Temperatura máxima do sensor (110ºC para 1.1V e 150ºC para > 1.5V)
float temperature = 0;							//Temperatura

//Variáveis do bargraph
const int bgPin[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

void setup()
{
	Serial.begin(9600);			//Leitura SERIAL
	analogReference(INTERNAL);	//Limita a entra analógica para 1.1V

	for (int x = 0; x < 10; x++) {
		pinMode(bgPin[x], OUTPUT);
	}
}

void loop()
{
	//Busca resultado do ADC
	unsigned int sensorADC = analogRead(sensorAnPin);

	//Converte a leitura em temperatura (conversão direta regra de três)
	temperature = (maxSensorTemperature / maxReaderSize) * sensorADC;

	//Ascende a luz de acordo com a temperatura
	for (int x = 0; x < 10; x++) {
		if (round(temperature * 10) > 250 + (bgPin[x] * 5)) {
			digitalWrite(bgPin[x], HIGH);
		} else {
			digitalWrite(bgPin[x], LOW);
		}
	}

	//DEBUGs
	Serial.print("Temperatura: ");
	Serial.println(temperature);


}

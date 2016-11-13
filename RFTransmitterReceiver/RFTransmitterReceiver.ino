#include <VirtualWire.h>

const int led_pin = 13;
const int transmit_pin = 8;
const int receive_pin = 13;
const int transmit_en_pin = 3;

//Loop
long previousMillis = 0;			 // Variável de controle do tempo
long transmitterInterval = 1000;     // Tempo em ms do intervalo a ser executado
int transmitterLedState = LOW;		//Stado do loop ou da led



void setup()
{
	// Initialise the IO and ISR
	vw_set_tx_pin(transmit_pin);
	vw_set_rx_pin(receive_pin);
	vw_set_ptt_pin(transmit_en_pin);
	vw_set_ptt_inverted(true); // Required for DR3100
	vw_setup(2000);	 // Bits per sec

	Serial.begin(9600);
	vw_rx_start();       // Start the receiver PLL running
}

byte count = 1;

void loop()
{
	unsigned long currentMillis = millis();    //Tempo atual em ms

	//Loop para o transmissor
	//if (currentMillis - previousMillis > transmitterInterval) {
	//	previousMillis = currentMillis;    // Salva o tempo atual

	//	char msg[7] = { 'h', 'e', 'l', 'l', 'o', ' ', '#' };	//Mensagem a ser enviada
	//	msg[6] = count;


	//	//E aqui muda o estado do led
	//	//verificando como ele estava anteriormente
	//	if (transmitterLedState == LOW) {
	//		transmitterLedState = HIGH;
	//	}
	//	else {
	//		transmitterLedState = LOW;
	//	}

	//	

	//	vw_send((uint8_t *)msg, 7);
	//	vw_wait_tx(); // Wait until the whole message is gone
	//	digitalWrite(led_pin, transmitterLedState);
	//	count = count + 1;
	//}

	//Receptor

	uint8_t buf[VW_MAX_MESSAGE_LEN];
	uint8_t buflen = VW_MAX_MESSAGE_LEN;


	if (vw_get_message(buf, &buflen)) // Non-blocking
	{
		int i;	

		// Message with a good checksum received, print it.
		Serial.print("Got: ");

		for (i = 0; i < buflen; i++)
		{
			Serial.print(char(buf[i]));
			Serial.print(' ');
		}
		Serial.println();
		digitalWrite(led_pin, LOW);
	}


}
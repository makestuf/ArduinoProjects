#include <SPI.h>
#include "RF24.h"

/****************** User Config ***************************/
/***      Set this radio as radio number 0 or 1         ***/
bool radioNumber = 1;

/**
  Create a data structure for transmitting and receiving data
  This allows many variables to be easily sent and received in a single transmission
  See http://www.cplusplus.com/doc/tutorial/structures/
*/
struct dataStruct {
  unsigned long _micros;
  int xAmplitude;
  int yAmplitude;
  bool Jbutton;
  bool Abutton;
  bool Bbutton;
  bool Gbutton;
  bool Fbutton;
  bool Ebutton;
  bool Dbutton;
} myData;

/* Hardware configuration: Set up nRF24L01 radio on SPI bus plus pins 7 & 8 */
RF24 radio(48, 49);
/**********************************************************/

byte addresses[][6] = {"1Node", "2Node"};

void setup() {
  Serial.begin(115200);
  radio.begin();

  // Set the PA Level low to prevent power supply related issues since this is a
  // getting_started sketch, and the likelihood of close proximity of the devices. RF24_PA_MAX is default.
  radio.setPALevel(RF24_PA_LOW);

  // Open a writing and reading pipe on each radio, with opposite addresses
  if (radioNumber) {
    radio.openWritingPipe(addresses[1]);
    radio.openReadingPipe(1, addresses[0]);
  } else {
    radio.openWritingPipe(addresses[0]);
    radio.openReadingPipe(1, addresses[1]);
  }

  // Start the radio listening for data
  radio.startListening();
}

void loop() {

  /****************** Pong Back Role ***************************/
  if ( radio.available()) {
    while (radio.available()) {                                   // While there is data ready
      radio.read(&myData, sizeof(myData));             // Get the payload
    }

    Serial.print(F("Sent response "));
    Serial.println(myData._micros);

    Serial.print("Joystick commands - x:");
    Serial.print(myData.xAmplitude);
    Serial.print(" y:");
    Serial.print(myData.yAmplitude);
    Serial.println();
  }

} // Loop


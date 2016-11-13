#include <SPI.h>
#include "RF24.h"
#include "JoystickShield_IS.h"

/****************** User Config ***************************/
/***      Set this radio as radio number 0 or 1         ***/
bool radioNumber = 0;

/* Hardware configuration: Set up nRF24L01 radio on SPI bus plus pins 7 & 8 */
RF24 radio(2, 10);

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

/* Create an instance of JoystickShield object */
JoystickShield joystickShield;

/* Debug mode */
bool radioDebugMode = true;
bool joystickDebug = true;
/**********************************************************/

byte addresses[][6] = {"1Node", "2Node"};

void setup() {
  Serial.begin(115200);
  radio.begin();

  //////////////////////////RADIO

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

  //////////////////////////JOYSTICK
  // new calibration function
  joystickShield.calibrateJoystick();

}

void loop() {
  /////////////////////////JOYSTICK
  joystickShield.processEvents(); // process events

  if (joystickShield.isJoystickButton()) {
    myData.Jbutton = true;
  } else {
    myData.Jbutton = false;
  }

  if (joystickShield.isAButton()) {
    myData.Abutton = true;
  } else {
    myData.Abutton = false;
  }

  if (joystickShield.isBButton()) {
    myData.Bbutton = true;
  } else {
    myData.Bbutton = false;
  }

  if (joystickShield.isGButton()) {
    myData.Gbutton = true;
  } else {
    myData.Gbutton = false;
  }

  if (joystickShield.isFButton()) {
    myData.Fbutton = true;
  } else {
    myData.Fbutton = false;
  }

  if (joystickShield.isEButton()) {
    myData.Ebutton = true;
  } else {
    myData.Ebutton = false;
  }

  if (joystickShield.isDButton()) {
    myData.Dbutton = true;
  }  else {
    myData.Dbutton = false;
  }

  // new position functions
  myData.xAmplitude = joystickShield.xAmplitude();
  myData.yAmplitude = joystickShield.yAmplitude();

  if (joystickDebug) {
    Serial.print("Joystick commands - x:");
    Serial.print(myData.xAmplitude);
    Serial.print(" y:");
    Serial.print(myData.yAmplitude);
    Serial.println();
  }


  /////////////////////////RADIO

  radio.stopListening();                                    // First, stop listening so we can talk.

  myData._micros = micros();                             // Take the time, and send it.  This will block until complete
  radio.write(&myData, sizeof(myData));

  radio.startListening();                                    // Now, continue listening

  unsigned long started_waiting_at = micros();               // Set up a timeout period, get the current microseconds
  boolean timeout = false;                                   // Set up a variable to indicate if a response was received or not

  while ( ! radio.available() ) {                            // While nothing is received
    if (micros() - started_waiting_at > 200000 ) {           // If waited longer than 200ms, indicate timeout and exit while loop
      timeout = true;
      break;
    }
  }

  if ( timeout ) {                                            // Describe the results
    if (radioDebugMode) {
      Serial.println(F("Failed, response timed out."));
    }
  } else {
    radio.read( &myData._micros, sizeof(myData._micros) );
    unsigned long time = micros();

    // Spew it
    if (radioDebugMode) {
      Serial.print(F("Sent "));
      Serial.print(time);
      Serial.print(F(", Got response "));
      Serial.print(myData._micros);
      Serial.print(F(", Round-trip delay "));
      Serial.print(time - myData._micros);
      Serial.println(F(" microseconds"));
    }
  }

  delay(1000);

}


#include "Robot.h"
#include "AFMotor.h"

//Motor
const int leftMotorSlot = 3;
const int rightMotorSlot = 4;

const int motorStarterSpeed = 125;
//const int motorRotateSpeed = 30;

int leftMotorSpeed = motorStarterSpeed;
int rightMotorSpeed = motorStarterSpeed;


void setup() {
	//Motor set
	Robot.setMotor(leftMotorSlot, rightMotorSlot);

	//Calibrate
	//calibrate();

	//Debug
	Serial.begin(9600);
}

void loop() {
}
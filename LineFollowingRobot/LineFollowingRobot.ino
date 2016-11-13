#include "Robot.h"
#include "AFMotor.h"

//Line Sensor
const int leftLineSensorPin = A4;
const int rightLineSensorPin = A5;

int leftLineSensorVal;
int rightLineSensorVal;

const int maxSensorVal = 2014;
const int lineThreshold = 900;

int normalStateSensorTopVal;

//Motor
const int leftMotorSlot = 3;
const int rightMotorSlot = 4;

const int motorStarterSpeed = 125;
//const int motorRotateSpeed = 30;

int leftMotorSpeed = motorStarterSpeed;
int rightMotorSpeed = motorStarterSpeed;


///////////////////////////////
// Calibrate
///////////////////////////////
void calibrate() {
	//Calibrate
	//TODO
	normalStateSensorTopVal = 1000;
}


void setup()
{
	//Motor set
	Robot.setMotor(leftMotorSlot, rightMotorSlot);

	//Calibrate
	calibrate();
	
	//Debug
	Serial.begin(9600);

}

void loop()
{
	//Read line sensor data
	leftLineSensorVal = analogRead(leftLineSensorPin);
	rightLineSensorVal = analogRead(rightLineSensorPin);

	Serial.print("leftSensor: ");
	Serial.print(leftLineSensorVal);
	Serial.print("        rightSensor: ");
	Serial.print(rightLineSensorVal);

	if (leftLineSensorVal > lineThreshold && rightLineSensorVal > lineThreshold) {
		Robot.stop();
		Serial.println();
		return;
	}

	//Have line on left?
	else if (leftLineSensorVal > lineThreshold) {
		leftMotorSpeed = motorStarterSpeed;
		rightMotorSpeed = 0;
		Serial.print("    >> Turn left");
	}

	//Have line on the right?
	else if (rightLineSensorVal > lineThreshold) {
		leftMotorSpeed = 0;
		rightMotorSpeed = motorStarterSpeed;
		Serial.print("    >> Turn right");
	}

	else {
		leftMotorSpeed = motorStarterSpeed;
		rightMotorSpeed = motorStarterSpeed;
		Serial.print("    >> Continue");
	}


	//Send command to Robot
	
	Robot.setLeftSpeed(leftMotorSpeed);
	Robot.setRightSpeed(rightMotorSpeed);
	

	if (leftMotorSpeed != rightMotorSpeed) {
		Robot.stop();
		delay(1);
		Robot.run();
		delay(1);
	}
	else {
		Robot.stop();
		delay(25);
		Robot.run();
		delay(10);
	}
	Serial.println();
}

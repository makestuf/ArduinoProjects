#include "Robot.h"

//TODO:Remove from here
AF_DCMotor leftMotor(3, MOTOR34_8KHZ);
AF_DCMotor rightMotor(4, MOTOR34_8KHZ);

//Set motor configuration
void RobotClass::setMotor(int leftSlot, int rightSlot) {
	//AF_DCMotor leftMotor(leftSlot);
	//AF_DCMotor rightMotor(rightSlot);
}

//Left motor speed
void RobotClass::setLeftSpeed(int speed) {
	leftMotor.setSpeed(speed);
}

//Right motor speed
void RobotClass::setRightSpeed(int speed) {
	rightMotor.setSpeed(speed);
}

//Set left and right speed
void RobotClass::setSpeed(int speed) {
	setLeftSpeed(speed);
	setRightSpeed(speed);
}

//Run!
void RobotClass::run() {
	leftMotor.run(BACKWARD);
	rightMotor.run(BACKWARD);
}

//STop
void RobotClass::stop() {
	leftMotor.run(RELEASE);
	rightMotor.run(RELEASE);
}

RobotClass Robot;


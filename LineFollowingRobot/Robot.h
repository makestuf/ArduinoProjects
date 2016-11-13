// Robot.h
#include "AFMotor.h"

#ifndef _ROBOT_h
#define _ROBOT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class RobotClass
{
 protected:
	 //static AF_DCMotor leftMotor;
	 //static AF_DCMotor rightMotor;
 public:
	void setMotor(int, int);
	void setLeftSpeed(int);
	void setRightSpeed(int);
	void setSpeed(int);
	void run();
	void stop();
};

extern RobotClass Robot;

#endif


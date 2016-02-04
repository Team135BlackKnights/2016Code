#ifndef Shooter_H
#define Shooter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "PIDLogging.h"
#include "LogData.h"

class Shooter: public PIDLogging
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	static const int RADIUS = 6;
	static const int NUM_MOTORS = 2;

	/* double PValue,
		   IValue,
		   DValue; */

public:
	static const int MOTOR_SHOOTER_RIGHT = 0;
	static const int MOTOR_SHOOTER_LEFT = 1;

	/*double PValue,
		   IValue,
		   DValue;
	*/
	Shooter();
	void InitDefaultCommand();
	void DriveMotor(int, double);

};

#endif

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

public:
	Shooter();
	void InitDefaultCommand();
	void SetMotorValue(int, double);

};

#endif

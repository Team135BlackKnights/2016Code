#ifndef Arm_H
#define Arm_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "PIDLogging.h"

class Arm: public PIDLogging
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Arm();
	void InitDefaultCommand();
	void RaiseLowerArm(float);

	static const int RAISE_LOWER_ARM = 0;
	static const int ARM_INVERSION = 1;
};

#endif
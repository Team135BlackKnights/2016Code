#ifndef PID_H
#define PID_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"

class PID: public PIDSubsystem
{
public:
	PID();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
};

#endif

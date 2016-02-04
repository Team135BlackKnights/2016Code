#ifndef Shooter_H
#define Shooter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "PIDLogging.h"

class Shooter: public PIDLogging
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	//  Motor for Two Wheels, motor for raising and lower arm, motor for collection of boulder
	std::unique_ptr<CANTalon> shooter;
public:
	Shooter();
	void InitDefaultCommand();
	void DriveMotor(int, double);

	static const int TWO_WHEEL_SHOOTER_MOTOR = 0;

};

#endif

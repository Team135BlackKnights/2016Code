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

	std::unique_ptr<Relay> kicker;

	//  Not defined yet
public:
	Shooter();
	void InitDefaultCommand();
	void DriveShooterMotors(float=1.0f);
	void StopShooterMotors();
	void RaiseLowerArm(double);

	void DriveKicker(Relay::Value);

	static const int TWO_WHEEL_SHOOTER_MOTOR = 0;
	static const int IN = 1;
	static const int OUT = -IN;

	static const Relay::Value KICKER_KICKED = Relay::Value::kForward;
	static const Relay::Value KICKER_RESET = Relay::Value::kOff;
};

#endif

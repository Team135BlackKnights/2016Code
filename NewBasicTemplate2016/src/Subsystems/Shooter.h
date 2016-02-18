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

	std::unique_ptr<Servo> kicker;

	//  Not defined yet
public:
	Shooter();
	void InitDefaultCommand();
	void DriveShooterMotors(float=.8f);
	void StopShooterMotors();
	void RaiseLowerArm(double);

	void DriveKicker(float);

	static const int TWO_WHEEL_SHOOTER_MOTOR = 0;
	static const int IN = -1;
	static const int OUT = -IN;

	static constexpr float KICKER_KICKED = 1.0f;
	static constexpr float KICKER_RESET = KICKER_KICKED == 1.0f ? 0.0f : 1.0f;
};

#endif
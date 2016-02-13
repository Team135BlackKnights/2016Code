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

	std::unique_ptr<Servo> servo;

	//  Not defined yet
public:
	Shooter();
	void InitDefaultCommand();
	void DriveShooterMotors(float=.8f);
	void StopShooterMotors();
	void RaiseLowerArm(double);

	void MoveServo();
	void ResetServoPosition();
	double GetServoPosition();

	static const int TWO_WHEEL_SHOOTER_MOTOR = 0;
};

#endif

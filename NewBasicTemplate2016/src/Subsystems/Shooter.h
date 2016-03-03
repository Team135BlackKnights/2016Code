#ifndef Shooter_H
#define Shooter_H

#include <Subsystems/EncoderLogging.h>
#include "Commands/Subsystem.h"
#include "WPILib.h"

class Shooter: public EncoderLogging
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	//  Declares a Servo that will be used the "kick" the ball out when the shooter motor is up to speed
	std::unique_ptr<Servo> kicker;
public:
	Shooter();
	void InitDefaultCommand();
	void DriveShooterMotor(float=1.0f);
	void StopShooterMotor();

	void DriveKicker(float);

	static const int TWO_WHEEL_SHOOTER_MOTOR = 0;

	//  When the shooter motor "suck the ball in" of go inwards, the motor power is going in a negative direction
	static const int IN = 1;
	//  Therefore, when the shooter motor shoots the ball outwards, the motor power is going in the positive direction
	static const int OUT = -IN;

	//  The positions in which the servos will go
	static constexpr float KICKER_KICKED = 0.6f;
	static constexpr float KICKER_RESET = 0.0f;
};

#endif

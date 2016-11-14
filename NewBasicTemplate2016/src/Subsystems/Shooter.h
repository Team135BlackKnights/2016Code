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
	//std::unique_ptr<Servo> kicker;
	std::unique_ptr<Solenoid> kicker;
	std::unique_ptr<Solenoid> unstucker;

	std::unique_ptr<Counter> shooterTracker;
	//std::unique_ptr<SerialPort> serial;

	//  Value Still To Be Determined
	static constexpr double SHOOTER_TRACKER_SETPOINT = 300.0;

	double currentConnerValue = 0.0,
		   tempConnerValue = 0.0;

public:
	Shooter();
	void InitDefaultCommand();
	void DriveShooterMotors(float=1.0f);
	void StopShooterMotors();
	void RaiseLowerArm(double);

	void DriveKicker(bool);
	void DriveUnstucker(bool);

	double GetShooterTrackerPeriod();
	double ConnerConversion(double);
	bool ShooterUpToSpeed();

	static const int TWO_WHEEL_SHOOTER_MOTOR = 0;
	static const int IN = 1.0f;
	static const int OUT = -IN;

	//static constexpr float KICKER_KICKED = 0.6f;
	//static constexpr float KICKER_RESET = 0.03f;

	static const bool KICKER_KICKED = true;
	static const bool KICKER_RESET = !KICKER_KICKED;

	static const bool SHOOTER_INVERTED = true;
};

#endif

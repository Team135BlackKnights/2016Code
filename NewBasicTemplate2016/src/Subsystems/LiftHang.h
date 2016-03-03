#ifndef LiftHang_H
#define LiftHang_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class LiftHang: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	//  Declares VictorSP's for the LiftHang System
	std::unique_ptr<VictorSP> liftMotor;
	std::unique_ptr<VictorSP> flipperMotor;


public:
	LiftHang();
	void InitDefaultCommand();
	void DriveLiftMotor(float);
	void DriveFlipperMotor(float);

	//  Depending upon how the motor is set up, the motor may need the user to set the motor power
	//  to a negative power in order to go upwards
	//  It all depends on how the motor is set up hardware wise

	//  The motor for lifting the system requires a positive value in order to go upwards
	static const int LIFT_UP = 1;
	static const int LIFT_DOWN = -LIFT_UP;

	//  The Flipper Up motor requires positive value in order to go upwards
	static const int FLIPPER_UP = 1;
	static const int FLIPPER_DOWN = -FLIPPER_UP;
};

#endif

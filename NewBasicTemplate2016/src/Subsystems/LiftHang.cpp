#include "LiftHang.h"
#include "../RobotMap.h"
#include "../Commands/DriveLiftHang.h"

LiftHang::LiftHang() :
		Subsystem("LiftHang")
{
	//  Declares the VictorSP's in their designated PWM slot on the RoboRIO
	liftMotor.reset(new VictorSP(MOTOR_LIFT_HANG_LIFT));
	flipperMotor.reset(new VictorSP(MOTOR_LIFT_HANG_FLIPPER));

}

void LiftHang::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveLiftHang());
}

// Drives the lift motor with the given motor speed
void LiftHang::DriveLiftMotor(float value) {
	liftMotor.get()->Set(value);
}

// Drives the flipper motor with the given motor speed
void LiftHang::DriveFlipperMotor(float value) {
	flipperMotor.get()->Set(value);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

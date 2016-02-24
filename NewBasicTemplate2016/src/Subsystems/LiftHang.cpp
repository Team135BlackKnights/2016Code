#include "LiftHang.h"
#include "../RobotMap.h"
#include "../Commands/DriveLiftHang.h"

LiftHang::LiftHang() :
		Subsystem("LiftHang")
{
	liftMotor.reset(new VictorSP(MOTOR_LIFT_HANG_LIFT));
	flipperMotor.reset(new VictorSP(MOTOR_LIFT_HANG_FLIPPER));

}

void LiftHang::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveLiftHang());
}

void LiftHang::DriveLiftMotor(float value) {
	liftMotor.get()->Set(value);
}

void LiftHang::DriveFlipperMotor(float value) {
	flipperMotor.get()->Set(value);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

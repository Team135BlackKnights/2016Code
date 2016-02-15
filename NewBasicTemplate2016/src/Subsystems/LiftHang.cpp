#include "LiftHang.h"
#include "../RobotMap.h"

LiftHang::LiftHang() :
		Subsystem("LiftHang")
{
	liftMotor.reset(new CANTalon(MOTOR_LIFT_HANG_LIFT));
	flipperMotor.reset(new CANTalon(MOTOR_LIFT_HANG_FLIPPER));

}

void LiftHang::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void LiftHang::DriveLiftMotor(float value) {
	liftMotor->Set(value);
}

void LiftHang::DriveFlipperMotor(float value) {
	flipperMotor->Set(value);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

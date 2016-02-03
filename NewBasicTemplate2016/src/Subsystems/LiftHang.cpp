#include "LiftHang.h"
#include "../RobotMap.h"

LiftHang::LiftHang() :
		Subsystem("LiftHang")
{
	motors.reset(new CANTalon(MOTOR_LIFT_HANG));

}

void LiftHang::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void LiftHang::DriveMotor(float value) {
	motors->Set(value);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

#include "LiftHang.h"
#include "../RobotMap.h"

LiftHang::LiftHang() :
		Subsystem("ExampleSubsystem")
{
	motors.reset(new CANTalon(MOTOR_LIFT_HAnG));

}

void LiftHang::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void LiftHang::DriveMotorSlider(int motorIndex, double SliderValue) {
	motors->Set(SliderValue);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

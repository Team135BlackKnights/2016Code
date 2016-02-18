#include "Arm.h"
#include "../RobotMap.h"
#include "../Commands/DriveArm.h"

Arm::Arm() :
	PIDLogging("Shooter", "/home/lvuser/", numMotors, radius)
{
	motors[RAISE_LOWER_ARM] = new CANTalon(MOTOR_RAISE_LOWER_ARM);
}

void Arm::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveArm());
}

void Arm::RaiseLowerArm(float motorPower) {
	motors[RAISE_LOWER_ARM]->Set(motorPower);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

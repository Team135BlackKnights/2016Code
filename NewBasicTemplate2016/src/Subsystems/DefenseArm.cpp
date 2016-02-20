#include "DefenseArm.h"
#include "../RobotMap.h"
#include "../Commands/DriveDefenseArm.h"

DefenseArm::DefenseArm() :
		Subsystem("DefenseArm")
{
	motor.reset(new CANTalon(MOTOR_DEFENSE_ARM));
}

void DefenseArm::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveDefenseArm());
}

void DefenseArm::DriveMotor(float power)
{
	motor->Set(power);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

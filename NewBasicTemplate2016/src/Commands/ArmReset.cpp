#include "ArmReset.h"
#include "RobotMap.h"

ArmReset::ArmReset()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(arm.get());
}

// Called just before this Command runs the first time
void ArmReset::Initialize()
{
	this->SetTimeout(15.0f);
	this->SetRunWhenDisabled(true);
}

// Called repeatedly when this Command is scheduled to run
void ArmReset::Execute()
{
	arm->RaiseLowerArm(power * Arm::UP);
}

// Make this return true when this Command no longer needs to run execute()
bool ArmReset::IsFinished()
{
	return arm->GetTopLimitSwitchValue();
}

// Called once after isFinished returns true
void ArmReset::End()
{
	arm->RaiseLowerArm(0.00000f);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmReset::Interrupted()
{

}

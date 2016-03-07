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

}

// Called repeatedly when this Command is scheduled to run
void ArmReset::Execute()
{
	arm->RaiseLowerArm(power * Arm::UP);
}

// Make this return true when this Command no longer needs to run execute()
bool ArmReset::IsFinished()
{
	return arm->GetEncoderPosition() >= Arm::ARM_DOWN_POSITION;
}

// Called once after isFinished returns true
void ArmReset::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmReset::Interrupted()
{

}

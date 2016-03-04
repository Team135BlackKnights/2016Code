#include "SetArmPosition.h"

SetArmPosition::SetArmPosition(int position)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	arm->SetEncoderPosition(position);
}

// Called just before this Command runs the first time
void SetArmPosition::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void SetArmPosition::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetArmPosition::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetArmPosition::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetArmPosition::Interrupted()
{

}

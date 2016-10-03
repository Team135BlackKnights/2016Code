#include "OverrideLimitSwitch.h"

OverrideLimitSwitch::OverrideLimitSwitch()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void OverrideLimitSwitch::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void OverrideLimitSwitch::Execute()
{
	arm->OverrideLimitSwitch();
}

// Make this return true when this Command no longer needs to run execute()
bool OverrideLimitSwitch::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void OverrideLimitSwitch::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OverrideLimitSwitch::Interrupted()
{
	End();
}

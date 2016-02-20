#include "RaiseArm.h"

RaiseArm::RaiseArm()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(arm.get());

	timer = new Timer();
}

// Called just before this Command runs the first time
void RaiseArm::Initialize()
{
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void RaiseArm::Execute()
{
	arm->RaiseLowerArm(.25 * arm->ARM_INVERSION);
}

// Make this return true when this Command no longer needs to run execute()
bool RaiseArm::IsFinished()
{
	return (timer->Get() > TimeRaise);
}

// Called once after isFinished returns true
void RaiseArm::End()
{
	arm->RaiseLowerArm(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RaiseArm::Interrupted()
{
	this->End();
}

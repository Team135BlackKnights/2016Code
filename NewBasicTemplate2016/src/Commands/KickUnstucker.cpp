#include "KickUnstucker.h"

KickUnstucker::KickUnstucker()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void KickUnstucker::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void KickUnstucker::Execute()
{
	shooter->DriveUnstucker(true);
}

// Make this return true when this Command no longer needs to run execute()
bool KickUnstucker::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void KickUnstucker::End()
{
	shooter->DriveUnstucker(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void KickUnstucker::Interrupted()
{
	this->End();
}

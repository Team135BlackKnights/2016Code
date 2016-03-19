#include <Commands/CheckSideSide.h>

CheckSideSide::CheckSideSide()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void CheckSideSide::Initialize()
{
	isgood = false;
}

// Called repeatedly when this Command is scheduled to run
void CheckSideSide::Execute()
{
	float dist = cam.get()->xDistanceToCenter();
	float pos = arm.get()->GetEncoderPosition();
	bool acheck = (pos <= (arm.get()->GetPotOrEncoderValueForAutomationOfArm(cam.get()->distanceToBlob()) + 5)) && (pos >= (arm.get()->GetPotOrEncoderValueForAutomationOfArm(cam.get()->distanceToBlob()) - 5));
	bool side = (dist >= -10 && dist <= 10);
	bool scheck = (shooter.get()->GetShooterTrackerPeriod() > 250);
	if(side)
		isgood = true;
}

// Make this return true when this Command no longer needs to run execute()
bool CheckSideSide::IsFinished()
{
	return isgood;
}

// Called once after isFinished returns true
void CheckSideSide::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CheckSideSide::Interrupted()
{

}

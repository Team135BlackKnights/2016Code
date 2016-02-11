#include "AutonomousDrive.h"
#include <algorithm>

AutonomousDrive::AutonomousDrive(float x, float y, int time = ALONGTIME)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain.get());

	timer = new Timer();

	this->x = x;
	this->y = y;
	this->targetTime = time;
}

// Called just before this Command runs the first time
void AutonomousDrive::Initialize()
{
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutonomousDrive::Execute()
{
	if(timer)
	DriveTrain(x,y);
}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousDrive::IsFinished()
{
	return timer->HasPeriodPassed(targetTime);
}

// Called once after isFinished returns true
void AutonomousDrive::End()
{
	driveTrain->DriveTank(0f,0f);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousDrive::Interrupted()
{

}

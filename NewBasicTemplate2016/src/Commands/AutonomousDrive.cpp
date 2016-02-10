#include "AutonomousDrive.h"

AutonomousDrive::AutonomousDrive()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void AutonomousDrive::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutonomousDrive::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousDrive::IsFinished()
{
	driveTrain->DriveTank(0f,0f);
	return false;
}

// Called once after isFinished returns true
void AutonomousDrive::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousDrive::Interrupted()
{

}

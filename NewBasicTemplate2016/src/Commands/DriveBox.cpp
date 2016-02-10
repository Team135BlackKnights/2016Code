#include "DriveBox.h"

DriveBox::DriveBox(bool PosNeg)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain.get());
	direction = (PosNeg == true) ? 1 : -1;
}

// Called just before this Command runs the first time
void DriveBox::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveBox::Execute()
{
	float speed = motorSpeed * direction;
	driveTrain->DriveTank(speed, speed);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveBox::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveBox::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveBox::Interrupted()
{

}

#include "ChangeInvertedDriveTrain.h"

ChangeInvertedDriveTrain::ChangeInvertedDriveTrain(bool invert)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	this->invert = invert;
}

// Called just before this Command runs the first time
void ChangeInvertedDriveTrain::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ChangeInvertedDriveTrain::Execute()
{
	oi->driver->DRIVE_TRAIN_INVERTED = this->invert;
}

// Make this return true when this Command no longer needs to run execute()
bool ChangeInvertedDriveTrain::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ChangeInvertedDriveTrain::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ChangeInvertedDriveTrain::Interrupted()
{

}

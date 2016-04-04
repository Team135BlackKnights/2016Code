#include "DriveFlashlight.h"

DriveFlashlight::DriveFlashlight()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(flashlight.get());
}

// Called just before this Command runs the first time
void DriveFlashlight::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveFlashlight::Execute()
{
	/*
	if (oi->GetButton(OI::MANIP, 7))
		flashlight->SetFlashlight(true);
	else
		flashlight->SetFlashlight(false);
	*/
	flashlight->SetFlashlight(!flashlight->on);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveFlashlight::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void DriveFlashlight::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveFlashlight::Interrupted()
{

}

#include "DriveFlashlight.h"

DriveFlashlight::DriveFlashlight()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(flashlight.get());
	switched = false;
	timer.reset(new Timer());
}

// Called just before this Command runs the first time
void DriveFlashlight::Initialize()
{
	switched = false;
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

	if (!switched) {
		flashlight->SetSolenoid(true);
		switched = true;
		timer->Reset();
		timer->Start();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveFlashlight::IsFinished()
{
	return timer->Get() > 3.0f;
}

// Called once after isFinished returns true
void DriveFlashlight::End()
{
	switched = false;
	timer->Stop();
	flashlight->SetSolenoid(false);
	flashlight->SwitchActiveSoul();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveFlashlight::Interrupted()
{
	this->End();
}

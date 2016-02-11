#include "RaiseAndLowerArm.h"

RaiseAndLowerArm::RaiseAndLowerArm(bool PosNeg)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(arm.get());
	sliderValue = 0;

	direction = PosNeg ? 1: -1;
}

// Called just before this Command runs the first time
void RaiseAndLowerArm::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void RaiseAndLowerArm::Execute()
{
	sliderValue = oi->GetStickSlider(OI::LEFT);
	arm->RaiseLowerArm(sliderValue * direction);
}

// Make this return true when this Command no longer needs to run execute()
bool RaiseAndLowerArm::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void RaiseAndLowerArm::End()
{
	arm->RaiseLowerArm(0);
	sliderValue = 0;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RaiseAndLowerArm::Interrupted()
{
	End();
}

#include "ChangeNeutralMode.h"

//  Input the mode depending upon if the robot should be in brake or coast mode
ChangeNeutralMode::ChangeNeutralMode(bool mode) {
	this->mode = mode;
}

// Called just before this Command runs the first time
void ChangeNeutralMode::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ChangeNeutralMode::Execute()
{
	//  If you input into this function false, the motors will be set at brake mode
	//  If you input true into this function, the motors will be set at coast mode
	driveTrain->SetNeutralMode(mode);
}

// Make this return true when this Command no longer needs to run execute()
bool ChangeNeutralMode::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ChangeNeutralMode::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ChangeNeutralMode::Interrupted()
{

}

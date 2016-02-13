#include "AutonomousDrive.h"
#include <algorithm>

AutonomousDrive::AutonomousDrive(float left, float right, MODE driveMode, int time, float distance)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain.get());

	this->left = left;
	this->right = right;

	if (driveMode == MODE::TIME){
		timer = new Timer();
		//this->targetTime = time;
		this->SetTimeout(time);
	}

	else if (driveMode == MODE::DISTANCE){}
	else if (driveMode == DEFENSE){}

	this->SetTimeout(time);

}

// Called just before this Command runs the first time
void AutonomousDrive::Initialize()
{
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutonomousDrive::Execute()
{

	driveTrain->DriveTank(left,right);
}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousDrive::IsFinished()
{
	return this->IsTimedOut();
}

// Called once after isFinished returns true
void AutonomousDrive::End()
{
	driveTrain->DriveTank(0.0f,0.0f);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousDrive::Interrupted()
{
	End();
}

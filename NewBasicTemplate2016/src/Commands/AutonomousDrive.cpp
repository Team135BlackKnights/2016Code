#include "AutonomousDrive.h"
#include <algorithm>

AutonomousDrive::AutonomousDrive(float left, float right, MODE driveMode, int time, float distance)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain.get());

	this->left = left; //Assigns parameters to private floats
	this->right = right;

	if (driveMode == MODE::TIME){ // Starts TIME mode
		timer = new Timer(); // Creates a new timer
		//this->targetTime = time;
		this->SetTimeout(time); // Sets timeout to parameter time
	}

	else if (driveMode == MODE::DISTANCE){} // Starts DISTANCE mode

	else if (driveMode == DEFENSE){ // Starts DEFENSE mode

	}


}

// Called just before this Command runs the first time
void AutonomousDrive::Initialize()
{
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutonomousDrive::Execute()
{

	driveTrain->DriveTank(left,right); // Drives robot with private left and right values
}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousDrive::IsFinished()
{
	return this->IsTimedOut(); // Returns true and ends instance if the command has timed out
}

// Called once after isFinished returns true
void AutonomousDrive::End()
{
	driveTrain->DriveTank(0.0f,0.0f); // Stops robot movement
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousDrive::Interrupted()
{
	End(); // Calls end() if command is interrupted
}

#include "AutonomousDrive.h"
#include "Subsystems/SerialCommunication.h"
#include <algorithm>

AutonomousDrive::AutonomousDrive(float left = DEFAULT::D_SPEED, float right = DEFAULT::D_SPEED, MODE driveMode = MODE::TIME, int time = DEFAULT::D_TIME, float distance = DEFAULT::D_DISTANCE)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain.get());

	timer = new Timer(); // Creates a new timer

	this->left = left; //Assigns parameters to private floats
	this->right = right;
	this->driveMode = driveMode;
	this->time = time;

	crookedDirection = 0;
	overDefense = false;

	this->SetTimeout(time); // Sets timeout to parameter time
}

// Called just before this Command runs the first time
void AutonomousDrive::Initialize()
{
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutonomousDrive::Execute(){

	float left = this->left, right = this->right;
	switch (driveMode) {
		case MODE::TIME: // Starts TIME mode
		case MODE::DISTANCE: // Starts DISTANCE mode
			break;
		case MODE::DEFENSE: // Starts DEFENSE mode

			//Check if Robot is crooked
			crookedDirection = serialCommunication->IsCrookedAndOffCenter();

			switch (crookedDirection){
				case SerialCommunication::DIRECTION::CROOKED_LEFT : //Robot is crooked left
					right *= CROOKED_ADJUST;
					break;

				case SerialCommunication::DIRECTION::CROOKED_RIGHT : //Robot is crooked Right
					//driveTrain->DriveTank(left * CROOKED_ADJUST, right);
					left *= CROOKED_ADJUST;
					break;

				case SerialCommunication::DIRECTION::NOT_CROOKED : //Robot is not crooked
					break;
				}



			break;
	}

	driveTrain->DriveTank(left,right);
}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousDrive::IsFinished()
{
	switch (driveMode) {
			case MODE::TIME: // Starts TIME mode
				return this->IsTimedOut();  // Returns true and ends instance if the command has timed out
				break;
			case MODE::DISTANCE: // Starts DISTANCE mode
				//return distanceReached
				break;
			case MODE::DEFENSE:
				overDefense = serialCommunication->OverDefense(); //Checks if the Robot is over the defense
				return overDefense; // Returns true and ends instance if the Robot has crossed the defense
	}
	return false;
}

// Called once after isFinished returns true
void AutonomousDrive::End()
{
	driveTrain->DriveTank(0.0f, 0.0f); // Stops robot movement
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousDrive::Interrupted()
{
	End(); // Calls end() if command is interrupted
}

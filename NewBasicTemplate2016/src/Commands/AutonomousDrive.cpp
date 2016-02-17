#include "AutonomousDrive.h"
#include "Subsystems/SerialCommunication.h"
#include <algorithm>

AutonomousDrive::AutonomousDrive(float left = DEFAULT::D_SPEED, float right = DEFAULT::D_SPEED, MODE driveMode = MODE::TIME, int time = DEFAULT::D_TIME, float distance = DEFAULT::D_DISTANCE)
{
	Requires(driveTrain.get());

	timer = new Timer(); // Creates a new timer

	//Assigns parameters to private floats
	this->left = left, this->right = right, this->driveMode = driveMode, this->time = time;

	//Assigns default values
	crookedDirection = 0, overDefense = false;

	//Sets timeout to time
	this->SetTimeout(time);
}


void AutonomousDrive::Initialize()
{
	timer->Start();
}


void AutonomousDrive::Execute(){

	float left = this->left, right = this->right;

	switch (driveMode) {

		case MODE::TIME: // Starts TIME mode

		case MODE::DISTANCE: // Starts DISTANCE mode
			break;

		case MODE::DEFENSE: // Starts DEFENSE mode
			crookedDirection = serialCommunication->IsCrookedAndOffCenter();

			switch (crookedDirection){

				case SerialCommunication::DIRECTION::CROOKED_LEFT : //Left
					right *= CROOKED_ADJUST;
					break;
				case SerialCommunication::DIRECTION::CROOKED_RIGHT : //Right
					left *= CROOKED_ADJUST;
					break;
				case SerialCommunication::DIRECTION::NOT_CROOKED : //Centered
					break;
				}
		break;
	}

	driveTrain->DriveTank(left,right);

}


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
				break;
			}
	return false;
}


void AutonomousDrive::End()
{
	driveTrain->DriveTank(0.0f, 0.0f);
}


void AutonomousDrive::Interrupted()
{
	End();
}

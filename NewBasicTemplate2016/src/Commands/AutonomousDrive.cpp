#include "AutonomousDrive.h"
#include <algorithm>

AutonomousDrive::AutonomousDrive(float left, float right, MODE driveMode, int time, float distance)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain.get());

	timer = new Timer(); // Creates a new timer

	this->left = left; //Assigns parameters to private floats
	this->right = right;
	this->driveMode = driveMode;
	this->time = time;


}

// Called just before this Command runs the first time
void AutonomousDrive::Initialize()
{
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutonomousDrive::Execute(){

	switch (MODE) {
		case MODE::TIME: // Starts TIME mode
			this->SetTimeout(time); // Sets timeout to parameter time
			driveTrain->DriveTank(left,right); // Drives robot with private left and right values

			break;
			//////////////////////////////////////////////////////

		case MODE::DISTANCE: // Starts DISTANCE mode
			//PUT CODE HERE EVENTUALLY!!!!!!!!!!
			break;
			//////////////////////////////////////////////////////

		case MODE::DEFENSE: // Starts DEFENSE mode
			//Gets Sonar and Light sensor values
			leftSonarDistance = serialCommunication->GetSerialValues(SerialCommunication::LEFT_SONAR_VALUE);
			rightSonarDistance = serialCommunication->GetSerialValues(SerialCommunication::RIGHT_SONAR_VALUE);
			lightSensorBrightness = serialCommunication->GetSerialValues(SerialCommunication::LIGHT_SENSOR_VALUE);

			if (lightSensorValue >)

			this->SetTimeout(time);
			driveTrain->DriveTank(left,right);

			//Checks if robot is out of defense
			//if(leftSonarDistance > MAX_SHIELD_DISTANCE && rightSonarDistance > MAX_SHIELD_DISTANCE && LightSensorCounter = 2)
				//driveTrain->DriveTank(0,0);

			//Checks if robot is sideways
			//if(SonarSensor1 > MAX_SHIELD_DISTANCE && SonarSensor2 > MAX_SHIELD_DISTANCE && lightSensorCounter = 1)
				//driveTrain->DriveTank(0,0);

			//ADD CODE TO DETECT WHICH WAY THE ROBOT IS TURNED
			break;

		}
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

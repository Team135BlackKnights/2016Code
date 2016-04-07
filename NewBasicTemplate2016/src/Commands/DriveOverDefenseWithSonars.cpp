#include "DriveOverDefenseWithSonars.h"

DriveOverDefenseWithSonars::DriveOverDefenseWithSonars(float motorPower)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(sonarSensors.get());
	Requires(driveTrain.get());

	this->motorPower = motorPower;

	rightOrLeft = DriveTrain::RIGHT_TURN;

	overDefense = false;
}

// Called just before this Command runs the first time
void DriveOverDefenseWithSonars::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveOverDefenseWithSonars::Execute()
{
	driveTrain->DriveTank(this->motorPower, this->motorPower);

	rightSonarOverDefense = sonarSensors->RightSonarOverDefense();
	leftSonarOverDefense = sonarSensors->LeftSonarOverDefense();

	if (rightSonarOverDefense && leftSonarOverDefense == false) {
		rightOrLeft = DriveTrain::RIGHT_TURN;
		offCenterRightTurn = true;
		initialDistance = driveTrain->GetDistanceInches(DriveTrain::FRONT_RIGHT);
	}
	else if (rightSonarOverDefense == false && leftSonarOverDefense) {
		rightOrLeft = DriveTrain::LEFT_TURN;
		offCenterLeftTurn = true;
		initialDistance = driveTrain->GetDistanceInches(DriveTrain::FRONT_LEFT);
	}
	else if (rightSonarOverDefense && leftSonarOverDefense) {
		if (offCenterRightTurn) {
			finalDistance = driveTrain->GetDistanceInches(DriveTrain::FRONT_RIGHT);
			driveTrain->CalculateAngleToTurnAfterCrossingDefense(initialDistance, finalDistance, rightOrLeft);
		}
		else if (offCenterLeftTurn) {
			finalDistance = driveTrain->GetDistanceInches(DriveTrain::FRONT_LEFT);
			driveTrain->CalculateAngleToTurnAfterCrossingDefense(initialDistance, finalDistance, rightOrLeft);
		}
		overDefense = true;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveOverDefenseWithSonars::IsFinished()
{
	return overDefense;
}

// Called once after isFinished returns true
void DriveOverDefenseWithSonars::End()
{
	driveTrain->DriveTank(0.0f, 0.0f);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveOverDefenseWithSonars::Interrupted()
{
	this->End();
}

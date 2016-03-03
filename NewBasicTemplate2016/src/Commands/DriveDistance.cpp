#include "DriveDistance.h"

DriveDistance::DriveDistance(double inchesDistance)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain.get());

	this->inchesDistance = inchesDistance;

	distanceFromRightEncoder = 0;
	distanceFromLeftEncoder = 0;

	leftDone = false;
	rightDone = false;

	intialDistance = 0;
	finalDistance = 0;
}

// Called just before this Command runs the first time
void DriveDistance::Initialize()
{
	//driveTrain->ZeroEncoder(DriveTrain::FRONT_RIGHT);
	//driveTrain->ZeroEncoder(DriveTrain::FRONT_LEFT);

	intialDistance = driveTrain->GetDistanceInches(DriveTrain::FRONT_RIGHT);
	finalDistance = intialDistance + this->inchesDistance;
}

// Called repeatedly when this Command is scheduled to run
void DriveDistance::Execute()
{
	//distanceFromLeftEncoder = driveTrain->GetDistanceInches(DriveTrain::FRONT_LEFT);
	distanceFromRightEncoder = driveTrain->GetDistanceInches(DriveTrain::FRONT_RIGHT);
	//std::cout << "Right distance: " << distanceFromRightEncoder << std::endl;

	/*if (distanceFromLeftEncoder >= finalDistance) {
		leftDone = true;
		leftMotorPower = 0;
	} */

	if (this->inchesDistance > 0) {
		if (distanceFromRightEncoder >= finalDistance) {
			rightDone = true;
			//leftDone = true;
			rightMotorPower = 0;
			leftMotorPower = 0;
		}
	}
	else if (this->inchesDistance < 0) {
		if (distanceFromRightEncoder <= finalDistance) {
			rightDone = true;
			//leftDone = true;
			rightMotorPower = 0;
			leftMotorPower = 0;
		}
	}

	driveTrain->DriveTank(leftMotorPower, rightMotorPower);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveDistance::IsFinished()
{
	//return leftDone && rightDone;
	return rightDone;
}

// Called once after isFinished returns true
void DriveDistance::End()
{
	driveTrain->DriveTank(0.0, 0.0);
	distanceFromRightEncoder = 0;
	distanceFromLeftEncoder = 0;
	rightDone = false;
	leftDone = false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveDistance::Interrupted()
{
	End();
}

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
}

// Called just before this Command runs the first time
void DriveDistance::Initialize()
{
	driveTrain->ZeroAllEncoders();
}

// Called repeatedly when this Command is scheduled to run
void DriveDistance::Execute()
{
	distanceFromLeftEncoder = driveTrain->GetDistanceInches(DriveTrain::REAR_LEFT);
	distanceFromRightEncoder = driveTrain->GetDistanceInches(DriveTrain::REAR_RIGHT);

	if (distanceFromLeftEncoder >= this->inchesDistance) {
		leftDone = true;
	}

	if (distanceFromRightEncoder >= this->inchesDistance) {
		rightDone = true;
	}

	driveTrain->DriveTank(motorPower, motorPower);

	if (rightDone == true && distanceFromLeftEncoder >= this->inchesDistance) {

	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveDistance::IsFinished()
{

}

// Called once after isFinished returns true
void DriveDistance::End()
{
	driveTrain->DriveTank(0, 0);
	distanceFromRightEncoder = 0;
	distanceFromLeftEncoder = 0;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveDistance::Interrupted()
{
	End();
}

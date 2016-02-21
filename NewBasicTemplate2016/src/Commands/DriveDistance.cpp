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
	driveTrain->ZeroEncoder(DriveTrain::REAR_LEFT);
	driveTrain->ZeroEncoder(DriveTrain::FRONT_LEFT);
}

// Called repeatedly when this Command is scheduled to run
void DriveDistance::Execute()
{
	distanceFromLeftEncoder = driveTrain->GetDistanceInches(DriveTrain::REAR_LEFT);
	distanceFromRightEncoder = driveTrain->GetDistanceInches(DriveTrain::REAR_RIGHT);
	//std::cout << distanceFromLeftEncoder << "  " << distanceFromRightEncoder << std::endl;
	if (distanceFromLeftEncoder >= this->inchesDistance) {
		leftDone = true;
		leftMotorPower = 0;
		//std::cout << "DOne";
	}

	if (distanceFromRightEncoder >= this->inchesDistance) {
		rightDone = true;
		rightMotorPower = 0;
		//std::cout << "DOne2";
	}

	driveTrain->DriveTank(leftMotorPower, rightMotorPower);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveDistance::IsFinished()
{
	if (leftDone == true && rightDone == true) {
		return true;
	}
	else {
		return false;
	}
}

// Called once after isFinished returns true
void DriveDistance::End()
{
	driveTrain->DriveTank(0.0, 0.0);
	distanceFromRightEncoder = 0;
	distanceFromLeftEncoder = 0;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveDistance::Interrupted()
{
	End();
}

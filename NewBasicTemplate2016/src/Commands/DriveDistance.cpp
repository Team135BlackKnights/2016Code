#include "DriveDistance.h"

DriveDistance::DriveDistance(int inchesDistance, float motorPower, bool zero)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain.get());

	this->inchesDistance = inchesDistance;

	this->zero = zero;

	leftMotorPower = motorPower;
	rightMotorPower = motorPower;
}

// Called just before this Command runs the first time
void DriveDistance::Initialize()
{
	if (this->zero) {
		//driveTrain->ZeroEncoder(DriveTrain::FRONT_RIGHT);
		driveTrain->ZeroEncoder(DriveTrain::FRONT_LEFT);
		leftInitialDistance = 0;
		//rightFinalDistance = this->inchesDistance;
		leftFinalDistance = this->inchesDistance;
	}
	else {
		//rightInitialDistance = driveTrain->GetDistanceInches(DriveTrain::FRONT_RIGHT);
		leftInitialDistance = driveTrain->GetDistanceInches(DriveTrain::FRONT_LEFT);
		//rightFinalDistance = rightInitialDistance + this->inchesDistance;
		leftFinalDistance = leftInitialDistance + this->inchesDistance;
	}
}

// Called repeatedly when this Command is scheduled to run
void DriveDistance::Execute()
{
	//rightCurrentDistance = driveTrain->GetDistanceInches(DriveTrain::FRONT_RIGHT);
	leftCurrentDistance = driveTrain->GetDistanceInches(DriveTrain::FRONT_LEFT);
	std::cout << "Current Distance" << leftCurrentDistance << std::endl;

	//std::cout << "Left: " << leftCurrentDistance << " Right: " << rightCurrentDistance << std::endl;

	if (this->inchesDistance > 0) {
		/*if (rightCurrentDistance >= rightFinalDistance) {
			rightDistanceReached = true;
			rightMotorPower = 0;
		}
		*/
		if (leftCurrentDistance >= leftFinalDistance) {
			leftDistanceReached = true;
			leftMotorPower = 0;
		}
	}
	else if (this->inchesDistance < 0) {
		/*if (rightCurrentDistance <= rightFinalDistance) {
			rightDistanceReached = true;
			rightMotorPower = 0;
		}
		*/
		if (leftCurrentDistance <= leftFinalDistance) {
			leftDistanceReached = true;
			leftMotorPower = 0;
		}
	}

	driveTrain->DriveTank(leftMotorPower, leftMotorPower);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveDistance::IsFinished()
{
	return (leftDistanceReached);
}

// Called once after isFinished returns true
void DriveDistance::End()
{
	driveTrain->DriveTank(0.0f, 0.0f);
	rightInitialDistance = 0;
	rightFinalDistance = 0;
	leftInitialDistance = 0;
	leftFinalDistance = 0;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveDistance::Interrupted()
{
	End();
}

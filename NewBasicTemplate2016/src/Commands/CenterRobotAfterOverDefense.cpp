#include "CenterRobotAfterOverDefense.h"

CenterRobotAfterOverDefense::CenterRobotAfterOverDefense(float motorPower)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain.get());

	this->motorPower = motorPower;

	angleDegrees = 0.0D;

	rightOrLeft = DriveTrain::RIGHT_TURN;
}

// Called just before this Command runs the first time
void CenterRobotAfterOverDefense::Initialize()
{
	angleDegrees = driveTrain->GetAngleToTurnAuto();

	rightOrLeft = driveTrain->GetDirectionToTurnAuto();

	//  For Turning Right
	if (rightOrLeft == DriveTrain::RIGHT_TURN) {
		leftInitialEncoderPosition = driveTrain->GetEncoderPosition(DriveTrain::FRONT_LEFT);
		leftEncoderPositionToTravel = leftInitialEncoderPosition + driveTrain->GetEncoderPositionToTurnAngle(angleDegrees);
	}
	//  For Turing Left
	else if (rightOrLeft == DriveTrain::LEFT_TURN) {
		leftInitialEncoderPosition = driveTrain->GetEncoderPosition(DriveTrain::FRONT_LEFT);
		leftEncoderPositionToTravel = leftInitialEncoderPosition - driveTrain->GetEncoderPositionToTurnAngle(angleDegrees);
	}
}

// Called repeatedly when this Command is scheduled to run
void CenterRobotAfterOverDefense::Execute()
{
	leftCurrentEncoderPosition = driveTrain->GetEncoderPosition(DriveTrain::FRONT_LEFT);
	//  For Turning Right
	if (this->rightOrLeft == DriveTrain::RIGHT_TURN) {
		driveTrain->DriveTank(this->motorPower, -this->motorPower);
		if (leftCurrentEncoderPosition >= leftEncoderPositionToTravel) {
			turnAngleReached = true;
		}
	}
	//  For Turning Left
	else if (this->rightOrLeft == DriveTrain::LEFT_TURN) {
		driveTrain->DriveTank(-this->motorPower, this->motorPower);
		if (leftCurrentEncoderPosition <= leftEncoderPositionToTravel) {
			turnAngleReached = true;
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool CenterRobotAfterOverDefense::IsFinished()
{
	return turnAngleReached;
}

// Called once after isFinished returns true
void CenterRobotAfterOverDefense::End()
{
	driveTrain->DriveTank(0.0f, 0.0f);

	leftEncoderPositionToTravel = 0;
	leftInitialEncoderPosition = 0;
	turnAngleReached = false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CenterRobotAfterOverDefense::Interrupted()
{
	this->End();
}

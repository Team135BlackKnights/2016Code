#include "TurnRobotAngle.h"

TurnRobotAngle::TurnRobotAngle(int angleDegrees, bool rightOrLeft)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain.get());

	this->angleDegrees = angleDegrees;

	this->rightOrLeft = rightOrLeft;
}

// Called just before this Command runs the first time
void TurnRobotAngle::Initialize()
{
	//  For Turning Right
	if (this->rightOrLeft) {
		rightInitialEncoderPosition = driveTrain->GetEncoderPosition(DriveTrain::FRONT_RIGHT);
		rightEncoderPositionToTravel = rightInitialEncoderPosition - driveTrain->GetEncoderPositionToTurnAngle(this->angleDegrees);
	}
	//  For Turing Left
	else if (!this->rightOrLeft) {
		rightInitialEncoderPosition = driveTrain->GetEncoderPosition(DriveTrain::FRONT_RIGHT);
		rightEncoderPositionToTravel = rightInitialEncoderPosition + driveTrain->GetEncoderPositionToTurnAngle(this->angleDegrees);
	}
}

// Called repeatedly when this Command is scheduled to run
void TurnRobotAngle::Execute()
{
	rightCurrentEncoderPosition = driveTrain->GetEncoderPosition(DriveTrain::FRONT_RIGHT);
	//  For Turning Right
	if (this->rightOrLeft) {
		driveTrain->DriveTank(MOTOR_POWER, -MOTOR_POWER);
		if (rightCurrentEncoderPosition <= rightEncoderPositionToTravel) {
			turnAngleReached = true;
		}
	}
	//  For Turning Left
	else if (!this->rightOrLeft) {
		driveTrain->DriveTank(-MOTOR_POWER, MOTOR_POWER);
		if (rightCurrentEncoderPosition >= rightEncoderPositionToTravel) {
			turnAngleReached = true;
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool TurnRobotAngle::IsFinished()
{
	return turnAngleReached;
}

// Called once after isFinished returns true
void TurnRobotAngle::End()
{
	driveTrain->DriveTank(0.0f, 0.0f);

	rightEncoderPositionToTravel = 0;
	rightInitialEncoderPosition = 0;
	turnAngleReached = false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnRobotAngle::Interrupted()
{
	End();
}

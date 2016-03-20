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
		leftInitialEncoderPosition = driveTrain->GetEncoderPosition(DriveTrain::FRONT_LEFT);
		leftEncoderPositionToTravel = leftInitialEncoderPosition + driveTrain->GetEncoderPositionToTurnAngle(this->angleDegrees);
	}
	//  For Turing Left
	else if (!this->rightOrLeft) {
		leftInitialEncoderPosition = driveTrain->GetEncoderPosition(DriveTrain::FRONT_LEFT);
		leftEncoderPositionToTravel = leftInitialEncoderPosition - driveTrain->GetEncoderPositionToTurnAngle(this->angleDegrees);
	}
}

// Called repeatedly when this Command is scheduled to run
void TurnRobotAngle::Execute()
{
	leftCurrentEncoderPosition = driveTrain->GetEncoderPosition(DriveTrain::FRONT_LEFT);
	//  For Turning Right
	if (this->rightOrLeft) {
		driveTrain->DriveTank(-MOTOR_POWER, MOTOR_POWER);
		if (leftCurrentEncoderPosition >= leftEncoderPositionToTravel) {
			turnAngleReached = true;
		}
	}
	//  For Turning Left
	else if (!this->rightOrLeft) {
		driveTrain->DriveTank(MOTOR_POWER, -MOTOR_POWER);
		if (leftCurrentEncoderPosition <= leftEncoderPositionToTravel) {
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

	leftEncoderPositionToTravel = 0;
	leftInitialEncoderPosition = 0;
	turnAngleReached = false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnRobotAngle::Interrupted()
{
	End();
}

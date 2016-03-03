#include "TurnRobotAngle.h"

//  From Drive Train Subsystem
	//RIGHT = true;
	//LEFT = false;
TurnRobotAngle::TurnRobotAngle(int angleToTurn, bool rightOrLeft)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain.get());

	this->angleToTurn = angleToTurn;

	directionToSpin = rightOrLeft ? -1: 1;
	this->rightOrLeft = rightOrLeft;

	currentEncoderPosition = 0;

	initialEncoderValue = 0;
	encoderPositionToTurn = 0;
}

// Called just before this Command runs the first time
void TurnRobotAngle::Initialize()
{
	initialEncoderValue = driveTrain->GetEncoderPosition(DriveTrain::FRONT_RIGHT);

	//  For Turning Right
	if (this->rightOrLeft == true) {
		encoderPositionToTurn = initialEncoderValue - driveTrain->GetEncoderPositionToTurnAngle(this->angleToTurn);
	}

	//  For Turning Left
	else if (this->rightOrLeft == false) {
		encoderPositionToTurn = initialEncoderValue + driveTrain->GetEncoderPositionToTurnAngle(this->angleToTurn);
	}

}

// Called repeatedly when this Command is scheduled to run
void TurnRobotAngle::Execute()
{
	currentEncoderPosition = driveTrain->GetEncoderPosition(DriveTrain::FRONT_RIGHT);

	driveTrain->DriveTank((motorPower * (-directionToSpin)), (motorPower * directionToSpin));
}

// Make this return true when this Command no longer needs to run execute()
bool TurnRobotAngle::IsFinished()
{
	//  For Turning Right
	if (this->rightOrLeft == true) {
		return currentEncoderPosition <= encoderPositionToTurn;
	}

	//  For Turning Left
	else if (this->rightOrLeft == false) {
		return currentEncoderPosition >= encoderPositionToTurn;
	}

	else {
		std::cout << "Error in TurnRobotAngle" << std::endl;
		return false;
	}
}

// Called once after isFinished returns true
void TurnRobotAngle::End()
{
	driveTrain->DriveTank(0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnRobotAngle::Interrupted()
{

}

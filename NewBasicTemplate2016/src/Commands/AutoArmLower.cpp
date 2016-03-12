#include "AutoArmLower.h"

AutoArmLower::AutoArmLower(bool armAuto)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(arm.get());

	this->armAuto = armAuto;

	currentEncoderPosition = 0;
	desiredEncoderPosition = 0;

	initialEncoderPosition = 0;
	lowerEncoderArmPosition = 0;
}

// Called just before this Command runs the first time
void AutoArmLower::Initialize()
{
	if (this->armAuto == Arm::AUTO_NON_LOW_BAR) {
		initialEncoderPosition = abs((double)arm->GetEncoderPosition());
		lowerEncoderArmPosition = arm->GetValueBasedOnAngle(ANGLE_TO_LOWER_ARM);
		desiredEncoderPosition = initialEncoderPosition - lowerEncoderArmPosition;
	}
	else if (this->armAuto == Arm::AUTO_LOW_BAR) {
		initialEncoderPosition = 0;
		lowerEncoderArmPosition = 0;
		desiredEncoderPosition = 0;
	}
}

// Called repeatedly when this Command is scheduled to run
void AutoArmLower::Execute()
{
	currentEncoderPosition = abs((double) arm->GetEncoderPosition());

	SmartDashboard::PutNumber("Current Encoder Arm Position:", currentEncoderPosition);

	if (currentEncoderPosition > desiredEncoderPosition) {
		arm->RaiseLowerArm(motorPower * Arm::DOWN);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutoArmLower::IsFinished()
{
	return (currentEncoderPosition <= desiredEncoderPosition);
}

// Called once after isFinished returns true
void AutoArmLower::End()
{
	arm->RaiseLowerArm(0.0f);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoArmLower::Interrupted()
{
	End();
}

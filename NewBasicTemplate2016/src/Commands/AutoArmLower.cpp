#include "AutoArmLower.h"

AutoArmLower::AutoArmLower(bool armAuto)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(arm.get());
	Requires(shooter.get());

	this->armAuto = armAuto;

	currentEncoderPosition = 0;
	desiredEncoderPosition = 0;

	this->SetTimeout(5.0f);
}

// Called just before this Command runs the first time
void AutoArmLower::Initialize()
{

	//shooter->DriveKicker(Shooter::KICKER_MID);
	if (this->armAuto == Arm::AUTO_NON_LOW_BAR) {
		desiredEncoderPosition = arm->GetValueBasedOnAngle(ANGLE_TO_LOWER_ARM);
	}
	else if (this->armAuto == Arm::AUTO_LOW_BAR) {
		desiredEncoderPosition = 0;
	}
}

// Called repeatedly when this Command is scheduled to run
void AutoArmLower::Execute()
{
	currentEncoderPosition = (double) arm->GetEncoderPosition();

	arm->RaiseLowerArm(MOTOR_POWER * Arm::DOWN);
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
	shooter->DriveKicker(Shooter::KICKER_RESET);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoArmLower::Interrupted()
{
	End();
}

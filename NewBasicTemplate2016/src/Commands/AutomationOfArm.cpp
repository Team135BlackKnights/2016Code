#include "AutomationOfArm.h"

AutomationOfArm::AutomationOfArm(double inchesHypotenuse)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(arm.get());
	currentArmEncoderValue = 0;
	desiredArmEncoderValue = 0;

	this->inchesHypotenuse = inchesHypotenuse;
}

// Called just before this Command runs the first time
void AutomationOfArm::Initialize()
{
	arm->ZeroEncoder();

	desiredArmEncoderValue = arm->GetEncoderValueForAngle(this->inchesHypotenuse);
}

// Called repeatedly when this Command is scheduled to run
void AutomationOfArm::Execute()
{
	currentArmEncoderValue = arm->GetEncoderPosition();

	if (currentArmEncoderValue < desiredArmEncoderValue) {
		arm->RaiseLowerArm(motorPowerUp);
	}
	else if (currentArmEncoderValue > desiredArmEncoderValue) {
		arm->RaiseLowerArm(motorPowerDown);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutomationOfArm::IsFinished()
{
	if (currentArmEncoderValue == desiredArmEncoderValue) {
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void AutomationOfArm::End()
{
	arm->RaiseLowerArm(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutomationOfArm::Interrupted()
{
	End();
}

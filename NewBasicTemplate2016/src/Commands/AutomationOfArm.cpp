#include "AutomationOfArm.h"

AutomationOfArm::AutomationOfArm()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(arm.get());

	currentValue = 0;
	desiredValue = 0;

}

// Called just before this Command runs the first time
void AutomationOfArm::Initialize()
{
	//desiredArmEncoderValue = arm->GetEncoderValueForAngle(cam.get()->distanceToBlob(cam.get()->getWidth()));

	//  The desired value of the arm should be at the position the function below returns
	desiredValue = (double) arm->GetPotOrEncoderValueForAutomationOfArm(cam.get()->distanceToBlob());
}

// Called repeatedly when this Command is scheduled to run
void AutomationOfArm::Execute()
{
	//  The currentValue updates every time Execute() runs
	currentValue = (double) arm->GetPotValueOrEncoderPosition();

	//  If the currentValue is lower than the desiredValue, then raise the arm upwards
	if (currentValue < desiredValue) {
		arm->RaiseLowerArm(motorPower * Arm::UP);
	}
	//  If the currentValue is higher than the desiredValue, then lower the arm
	else if (currentValue > desiredValue) {
		arm->RaiseLowerArm(motorPower * Arm::DOWN);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutomationOfArm::IsFinished()
{
	//return currentArmEncoderValue == desiredArmEncoderValue;
	//return currentPotValue = desiredPotValue;
	return false;
}

// Called once after isFinished returns true
void AutomationOfArm::End()
{
	arm->RaiseLowerArm(0.0f);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutomationOfArm::Interrupted()
{
	End();
}

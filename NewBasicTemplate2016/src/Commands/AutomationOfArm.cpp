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
	//std::cout << "encoder value : "<< desiredArmEncoderValue << std::endl;
	desiredValue = (double) arm->GetPotOrEncoderValueForAutomationOfArm(cam.get()->distanceToBlob());
}

// Called repeatedly when this Command is scheduled to run
void AutomationOfArm::Execute()
{
	currentValue = (double) arm->GetPotValueOrEncoderPosition();

	if (currentValue < desiredValue) {
		arm->RaiseLowerArm(motorPower * Arm::UP);
	}
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
	arm->RaiseLowerArm(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutomationOfArm::Interrupted()
{
	End();
}

#include "AutomationOfArm.h"

AutomationOfArm::AutomationOfArm()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(arm.get());
	currentArmEncoderValue = 0;
	desiredArmEncoderValue = 0;

	desiredPotValue = 0;
	currentPotValue = 0;

}

// Called just before this Command runs the first time
void AutomationOfArm::Initialize()
{
	//desiredArmEncoderValue = arm->GetEncoderValueForAngle(cam.get()->distanceToBlob(cam.get()->getWidth()));
	//std::cout << "encoder value : "<< desiredArmEncoderValue << std::endl;
	//desiredPotValue = arm->GetPotValueForArm(cam.get()->distanceToBlob(cam.get()->getWidth()));
}

// Called repeatedly when this Command is scheduled to run
void AutomationOfArm::Execute()
{
	currentPotValue = arm->GetPotValue();

	if (currentPotValue < desiredPotValue) {
		arm->RaiseLowerArm(motorPower * Arm::UP);
	}
	else if (currentPotValue > desiredPotValue) {
		arm->RaiseLowerArm(motorPower * Arm::DOWN);
	}

	/*currentArmEncoderValue = arm->GetEncoderPosition();

	if (currentArmEncoderValue < desiredArmEncoderValue) {
		arm->RaiseLowerArm(motorPower * Arm::UP);
	}
	else if (currentArmEncoderValue > desiredArmEncoderValue) {
		arm->RaiseLowerArm(motorPower * Arm::DOWN);
	}
	//std::cout << currentArmEncoderValue << std::endl; */
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

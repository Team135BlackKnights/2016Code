#include "AutomationOfArm.h"

AutomationOfArm::AutomationOfArm()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(arm.get());

	currentValue = 0;
	desiredValue = -1;
	startingValue = 0;
	this->angle = 0;
}

AutomationOfArm::AutomationOfArm(double angle)
{
	Requires(arm.get());
	currentValue = 0;
	desiredValue = arm->GetValueBasedOnAngle(angle);
	startingValue = 0;
	this->angle = angle;
}

// Called just before this Command runs the first time
void AutomationOfArm::Initialize()
{
	//desiredArmEncoderValue = arm->GetEncoderValueForAngle(cam.get()->distanceToBlob(cam.get()->getWidth()));
	//std::cout << "encoder value : "<< desiredArmEncoderValue << std::endl;
	startingValue = arm->GetPotValueOrEncoderPosition();

	if (desiredValue == -1)
		desiredValue = (double) arm->GetPotOrEncoderValueForAutomationOfArm(cam.get()->distanceToBlob());
		std::cout << desiredValue;
	SetTimeout(10.0);
	//std::cout << "Desired Value: " << desiredValue << std::endl;
}

// Called repeatedly when this Command is scheduled to run
void AutomationOfArm::Execute()
{
	currentValue = (double) arm->GetPotValueOrEncoderPosition();
	std::cout << "Current Value: " << currentValue << std::endl;
	std::cout << "Desired Value: " << desiredValue << std::endl;
	std::cout << "Angle: " << currentValue * 90.0D / 64.0D << '\n';
	if (currentValue < desiredValue) {
		arm->RaiseLowerArm(Arm::UP);
	}
	else if (currentValue > desiredValue) {
		arm->RaiseLowerArm(Arm::DOWN);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutomationOfArm::IsFinished()
{
	//return currentArmEncoderValue == desiredArmEncoderValue;
	//return currentPotValue = desiredPotValue;
	return startingValue < desiredValue ? currentValue >= desiredValue : currentValue <= desiredValue;
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

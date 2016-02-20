#include "AutomationOfArm.h"

AutomationOfArm::AutomationOfArm()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	//Requires(arm.get());
	//armEncoderValue = 0;
	//desiredArmEncoderValue = 0;
}

// Called just before this Command runs the first time
void AutomationOfArm::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutomationOfArm::Execute()
{
	//armEncoderValue = arm->GetEncoderPosition(Arm::RAISE_LOWER_ARM);
	//desiredArmEncoderValue = arm->GetEncoderValueForAngle();
}

// Make this return true when this Command no longer needs to run execute()
bool AutomationOfArm::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutomationOfArm::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutomationOfArm::Interrupted()
{

}

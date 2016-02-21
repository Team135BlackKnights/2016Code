#include "DriveDefenseArm.h"

DriveDefenseArm::DriveDefenseArm()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(defenseArm.get());
}

// Called just before this Command runs the first time
void DriveDefenseArm::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveDefenseArm::Execute()
{
	float power = 0;
	if (oi->GetButton(oi->CONTROL_DEFENSE_ARM_UP[0], oi->CONTROL_DEFENSE_ARM_UP[1]))
		power = DefenseArm::UP;
	else if (oi->CONTROL_DEFENSE_ARM_DOWN[0], oi->CONTROL_DEFENSE_ARM_DOWN[1])
		power = DefenseArm::DOWN;

	defenseArm->DriveMotor(power);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveDefenseArm::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveDefenseArm::End()
{
	defenseArm->DriveMotor(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveDefenseArm::Interrupted()
{
	this->End();
}

#include <Commands/DriveArm.h>

DriveArm::DriveArm()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(arm.get());
}

// Called just before this Command runs the first time
void DriveArm::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveArm::Execute()
{
	float y = oi->GetStickAxis(oi->manipulator->CONTROL_ARM_STICK, oi->manipulator->CONTROL_ARM_AXIS);
	arm->RaiseLowerArm(y * Arm::UP * (oi->manipulator->CONTROL_ARM_INVERTED ? -1 : 1));

	//std::cout << arm->GetPotValueOrEncoderPosition() << std::endl;
}

// Make this return true when this Command no longer needs to run execute()
bool DriveArm::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveArm::End()
{
	arm->RaiseLowerArm(0.0f);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveArm::Interrupted()
{
	End();
}

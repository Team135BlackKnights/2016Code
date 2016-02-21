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
	float y = oi->GetStickY(OI::MANIP);
	arm->RaiseLowerArm(y * Arm::UP);
	//std::cout << arm->GetEncoderPosition() << std::endl;
}

// Make this return true when this Command no longer needs to run execute()
bool DriveArm::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveArm::End()
{
	arm->RaiseLowerArm(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveArm::Interrupted()
{
	End();
}

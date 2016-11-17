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
	float y = oi->GetStickAxis(oi->CONTROL_ARM_STICK, oi->CONTROL_ARM_AXIS);
	if (oi->IsPressed(oi->CONTROL_ARM_STOP))
		y = 0;
	float power = y * Arm::UP * (oi->CONTROL_ARM_INVERTED ? -1 : 1);

	//if (abs(power) < 0.05f)
		//power = 0.0f;

	arm->RaiseLowerArm(power);// !oi->GetButton(oi->manipulator->CONTROL_ARM_REMOVE_SOFT_STOP[STICK], oi->manipulator->CONTROL_ARM_REMOVE_SOFT_STOP[BUTTON]));


	//std::cout << arm->GetPotValue() << std::endl;
	std::cout << "Arm Angle: " << arm->GetEncoderPosition() * 90/64 << std::endl;
	std::cout << "arm pos: " << arm->GetEncoderPosition() << std::endl;
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

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
	//  Get the value of the y-axis on the Maniupulator Joystick, since that value will be between -1 and 1
	//  and Input it into the RaiseLowerArm Function
	float y = oi->GetStickAxis(oi->manipulator->CONTROL_ARM_STICK, oi->manipulator->CONTROL_ARM_AXIS);
	//  Multiply "y" by Arm::Up because when "y" is positive, you want the arm to be moving up
	//  If y is negative, you want the arm to be moving downwards
	//  If the arm is inverted, multiply it by -1, false, multiply by 1
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
	//  Stop the motor from running when the command isn't executing
	arm->RaiseLowerArm(0.0f);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveArm::Interrupted()
{
	End();
}

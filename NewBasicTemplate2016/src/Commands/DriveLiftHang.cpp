#include "DriveLiftHang.h"

DriveLiftHang::DriveLiftHang(bool PosNeg)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(liftHang.get());
	direction = PosNeg ? 1: -1; //Ternary operator = bae
}

// Called just before this Command runs the first time
void DriveLiftHang::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void DriveLiftHang::Execute()
{
	float sliderValue = oi->GetStickSlider(OI::LIFT_HANG_JOYSTICK);
	float power;
	liftHang->DriveMotor(sliderValue * direction);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveLiftHang::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveLiftHang::End()
{
	liftHang->DriveMotor(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveLiftHang::Interrupted()
{
	this->End();
}

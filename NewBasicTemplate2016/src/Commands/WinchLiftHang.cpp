#include "WinchLiftHang.h"

WinchLiftHang::WinchLiftHang(float power)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	this->power = power;

}

// Called just before this Command runs the first time
void WinchLiftHang::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void WinchLiftHang::Execute()
{
	liftHang->DriveLiftMotor(power);
}

// Make this return true when this Command no longer needs to run execute()
bool WinchLiftHang::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void WinchLiftHang::End()
{
	liftHang->DriveLiftMotor(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WinchLiftHang::Interrupted()
{
	End();
}

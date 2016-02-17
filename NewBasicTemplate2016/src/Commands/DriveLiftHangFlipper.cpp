#include "DriveLiftHangFlipper.h"
#include "OI.h"

DriveLiftHangFlipper::DriveLiftHangFlipper(bool direction)
{
	// Use Requires() here to declare subsystem dependencies
	this->direction = direction ? 1 : -1;
	//Requires(liftHang.get());
}

// Called just before this Command runs the first time
void DriveLiftHangFlipper::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveLiftHangFlipper::Execute()
{
	float power = oi->GetStickSlider(OI::MANIP);
	liftHang->DriveFlipperMotor(power * direction);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveLiftHangFlipper::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveLiftHangFlipper::End()
{
	liftHang->DriveFlipperMotor(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveLiftHangFlipper::Interrupted()
{
	this->End();
}

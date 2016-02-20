#include "DriveLiftHang.h"
#include <Subsystems/LiftHang.h>
#include "OI.h"

DriveLiftHang::DriveLiftHang()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(liftHang.get());
}

// Called just before this Command runs the first time
void DriveLiftHang::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void DriveLiftHang::Execute()
{
	float slider = oi->GetStickSlider(OI::MANIP);
	float liftPower = 0, flipperPower = 0;

	if (oi->GetButton(oi->CONTROL_LIFT_HANG_UP[0], oi->CONTROL_LIFT_HANG_UP[1]))
		liftPower = slider * LiftHang::LIFT_UP;
	if (oi->GetButton(oi->CONTROL_LIFT_HANG_DOWN[0], oi->CONTROL_LIFT_HANG_DOWN[1]))
		liftPower = slider * LiftHang::LIFT_DOWN;
	liftHang->DriveLiftMotor(liftPower);

	if (oi->GetButton(oi->CONTROL_LIFT_HANG_FLIPPER_UP[0], oi->CONTROL_LIFT_HANG_FLIPPER_UP[1]))
		flipperPower = slider * LiftHang::FLIPPER_UP;
	if (oi->GetButton(oi->CONTROL_LIFT_HANG_FLIPPER_DOWN[0], oi->CONTROL_LIFT_HANG_FLIPPER_DOWN[1]))
		flipperPower = slider * LiftHang::FLIPPER_DOWN;
	liftHang->DriveFlipperMotor(flipperPower);


}

// Make this return true when this Command no longer needs to run execute()
bool DriveLiftHang::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveLiftHang::End()
{
	liftHang->DriveLiftMotor(0);
	liftHang->DriveFlipperMotor(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveLiftHang::Interrupted()
{
	this->End();
}

#include <Commands/DriveLiftHangWinch.h>
#include <Subsystems/LiftHangWinch.h>
#include "OI.h"

DriveLiftHangWinch::DriveLiftHangWinch(float power)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(liftHangWinch.get());
	this->power = power;
}

// Called just before this Command runs the first time
void DriveLiftHangWinch::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void DriveLiftHangWinch::Execute()
{
	//float sliderPower = oi->GetStickSlider(oi->manipulator->CONTROL_LIFT_HANG_FLIPPER_POWER_SLIDER);

	liftHangWinch->DriveMotor(power);

	/*
	if (oi->GetButton(oi->manipulator->CONTROL_LIFT_HANG_UP[STICK], oi->manipulator->CONTROL_LIFT_HANG_UP[BUTTON]))
		liftPower = liftPowerSlider * LiftHangWinch::WINCH_UP;
	if (oi->GetButton(oi->manipulator->CONTROL_LIFT_HANG_DOWN[STICK], oi->manipulator->CONTROL_LIFT_HANG_DOWN[BUTTON]))
		liftPower = liftPowerSlider * LiftHangWinch::WINCH_DOWN;
	liftHang->DriveMotor(liftPower);
	*/

	/*
	if (oi->GetButton(oi->manipulator->CONTROL_LIFT_HANG_FLIPPER_UP[STICK], oi->manipulator->CONTROL_LIFT_HANG_FLIPPER_UP[BUTTON]))
		flipperPower = flipperPowerSlider * LiftHangWinch::FLIPPER_UP;
	if (oi->GetButton(oi->manipulator->CONTROL_LIFT_HANG_FLIPPER_DOWN[STICK], oi->manipulator->CONTROL_LIFT_HANG_FLIPPER_DOWN[BUTTON]))
		flipperPower = flipperPowerSlider * LiftHangWinch::FLIPPER_DOWN;
	liftHang->DriveFlipperMotor(flipperPower);
	*/


}

// Make this return true when this Command no longer needs to run execute()
bool DriveLiftHangWinch::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveLiftHangWinch::End()
{
	liftHangWinch->DriveMotor(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveLiftHangWinch::Interrupted()
{
	this->End();
}

#include "DriveLiftHang.h"
#include <Subsystems/LiftHang.h>
#include "OI.h"

DriveLiftHang::DriveLiftHang()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(liftHang.get());

	liftPowerSlider = 0;
	flipperPowerSlider = 0;

	liftPower = 0;
	flipperPower = 0;
}

// Called just before this Command runs the first time
void DriveLiftHang::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void DriveLiftHang::Execute()
{
	//  The power of the liftHang systems are determined by the slider on two of the joysticks
	liftPowerSlider = oi->GetStickSlider(oi->manipulator->CONTROL_LIFT_HANG_POWER_SLIDER);
	flipperPowerSlider = oi->GetStickSlider(oi->manipulator->CONTROL_LIFT_HANG_FLIPPER_POWER_SLIDER);
	liftPower = 0;
	flipperPower = 0;

	//  If the designated button is pressed
	if (oi->GetButton(oi->manipulator->CONTROL_LIFT_HANG_UP[STICK], oi->manipulator->CONTROL_LIFT_HANG_UP[BUTTON]))
		//  liftPower = the power value from the slider multiplied  by LiftHang::LIFT__UP
		//  LiftHang::LIFT_UP acts as an inverter to the motor
		//  The SliderValue returns a value between 0 and 1,
		//  so in order for the lift motor to go in the negative direction, you have to multiply the value by -1
		liftPower = liftPowerSlider * LiftHang::LIFT_UP;

	//  If the designated button is pressed
	if (oi->GetButton(oi->manipulator->CONTROL_LIFT_HANG_DOWN[STICK], oi->manipulator->CONTROL_LIFT_HANG_DOWN[BUTTON]))
		//  LiftHang::LIFT_UP acts as an inverter to the motor
		//  The SliderValue returns a value between 0 and 1,
		//  so in order for the lift motor to go in the negative direction, you have to multiply the value by -1
		liftPower = liftPowerSlider * LiftHang::LIFT_DOWN;

	//  Drive the Lift Motor given the value of liftPower, calculated above
	liftHang->DriveLiftMotor(liftPower);

	//  Same notes from above apply to this section of code as well
	if (oi->GetButton(oi->manipulator->CONTROL_LIFT_HANG_FLIPPER_UP[STICK], oi->manipulator->CONTROL_LIFT_HANG_FLIPPER_UP[BUTTON]))
		flipperPower = flipperPowerSlider * LiftHang::FLIPPER_UP;
	if (oi->GetButton(oi->manipulator->CONTROL_LIFT_HANG_FLIPPER_DOWN[STICK], oi->manipulator->CONTROL_LIFT_HANG_FLIPPER_DOWN[BUTTON]))
		flipperPower = flipperPowerSlider * LiftHang::FLIPPER_DOWN;
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
	//  When the command ends, stop the liftMotor and flipperMotor from running
	liftHang->DriveLiftMotor(0.0f);
	liftHang->DriveFlipperMotor(0.0f);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveLiftHang::Interrupted()
{
	this->End();
}

#include <Commands/DriveLiftHangFlipper.h>
#include <Subsystems/LiftHangFlipFlip.h>

DriveLiftHangFlipper::DriveLiftHangFlipper(float direction)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(liftHangFlip.get());
	this->direction = direction;
}

// Called just before this Command runs the first time
void DriveLiftHangFlipper::Initialize()
{
	//Requires()
}

// Called repeatedly when this Command is scheduled to run
void DriveLiftHangFlipper::Execute()
{
	float power = 0.5f;//oi->GetStickSlider(oi->manipulator->CONTROL_LIFT_HANG_FLIPPER_POWER_SLIDER);
	liftHangFlip->DriveMotor(direction * power);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveLiftHangFlipper::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveLiftHangFlipper::End()
{
	liftHangFlip->DriveMotor(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveLiftHangFlipper::Interrupted()
{
	this->End();
}

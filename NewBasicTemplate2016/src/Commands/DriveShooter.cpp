#include "DriveShooter.h"

DriveShooter::DriveShooter()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(shooter.get());
}

// Called just before this Command runs the first time
void DriveShooter::Initialize()
{
	shooter->DriveKicker(Shooter::KICKER_RESET);
}

// Called repeatedly when this Command is scheduled to run
void DriveShooter::Execute()
{
	float power = 0;
	motorPower = oi->GetStickSlider(oi->MANIP);//Preferences::GetInstance()->GetFloat("Shooter Power", motorPower);
	if (oi->GetButton(oi->CONTROL_SHOOTER_OUT[0], oi->CONTROL_SHOOTER_OUT[1]))//oi->CONTROL_SHOOT[0], oi->CONTROL_SHOOT[1]))
		power = motorPower * Shooter::OUT;
	else if (oi->GetButton(oi->CONTROL_SHOOTER_IN[0], oi->CONTROL_SHOOTER_IN[1]))//oi->CONTROL_COLLECTION_IN[0], oi->CONTROL_COLLECTION_IN[1]))
		power = motorPower * Shooter::IN;
	shooter->DriveShooterMotors(power);

	if (oi->GetButton(oi->CONTROL_SHOOTER_KICKER_KICK[0], oi->CONTROL_SHOOTER_KICKER_KICK[1]))
		shooter->DriveKicker(Shooter::KICKER_KICKED);
	else if (oi->GetButton(oi->CONTROL_SHOOTER_KICKER_RESET[0], oi->CONTROL_SHOOTER_KICKER_RESET[1]))
		shooter->DriveKicker(Shooter::KICKER_RESET);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveShooter::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveShooter::End()
{
	shooter->DriveShooterMotors(0);
	shooter->DriveKicker(Shooter::KICKER_RESET);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveShooter::Interrupted()
{
	this->End();
}

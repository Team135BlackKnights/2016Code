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
	//std::cout << shooter->GetEncoderPosition(Shooter::TWO_WHEEL_SHOOTER_MOTOR) << std::endl;
	float power = 0;
	motorPower = oi->GetStickSlider(oi->manipulator->CONTROL_SHOOTER_POWER_SLIDER);//Preferences::GetInstance()->GetFloat("Shooter Power", motorPower);
	if (oi->GetButton(oi->manipulator->CONTROL_SHOOTER_OUT[STICK], oi->manipulator->CONTROL_SHOOTER_OUT[BUTTON]))//oi->CONTROL_SHOOT[0], oi->CONTROL_SHOOT[1]))
		power = motorPower * Shooter::OUT;
	else if (oi->GetButton(oi->manipulator->CONTROL_SHOOTER_IN[STICK], oi->manipulator->CONTROL_SHOOTER_IN[BUTTON]))//oi->CONTROL_COLLECTION_IN[0], oi->CONTROL_COLLECTION_IN[1]))
		power = motorPower * Shooter::IN;
	shooter->DriveShooterMotor(power);

	//if (oi->GetButton(oi->manipulator->CONTROL_SHOOTER_KICKER_KICK[STICK], oi->manipulator->CONTROL_SHOOTER_KICKER_KICK[BUTTON]))
	if (oi->IsPressed(oi->manipulator->CONTROL_SHOOTER_KICKER_KICK))
		shooter->DriveKicker(Shooter::KICKER_KICKED);
	else //if (oi->GetButton(oi->manipulator->CONTROL_SHOOTER_KICKER_RESET[STICK], oi->manipulator->CONTROL_SHOOTER_KICKER_RESET[BUTTON]))
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
	shooter->DriveShooterMotor(0.0f);
	shooter->DriveKicker(Shooter::KICKER_RESET);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveShooter::Interrupted()
{
	this->End();
}

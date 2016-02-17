#include "ShootBoulder.h"

ShootBoulder::ShootBoulder()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(shooter.get());
	speedSet = false;
	encoderVelocity = 0;

	timer.reset(new Timer());
	initalTimerValue = 0;
	finalTimerValue = 0;
	timeWait = .2;

	placer = 0;
}

// Called just before this Command runs the first time
void ShootBoulder::Initialize()
{
	shooter->ZeroAllEncoders();
	timer->Reset();
}

// Called repeatedly when this Command is scheduled to run
void ShootBoulder::Execute()
{
	encoderVelocity = shooter->GetEncoderVelocity(Shooter::TWO_WHEEL_SHOOTER_MOTOR);

	shooter->DriveShooterMotors();

	if (encoderVelocity >= setEncoderVelocity) {
		placer = placer + 1;
		speedSet = true;
		SmartDashboard::PutBoolean("Shooter Up to Speed: ", speedSet);

		if (placer == 1) {
			initalTimerValue = timer->Get();
			finalTimerValue = initalTimerValue + timeWait;
		}
		if (finalTimerValue >= timer->Get()) {
			shooter->DriveKicker(.5f);
		}
	}
	else {
		placer = 0;
		speedSet = false;
		SmartDashboard::PutBoolean("Shooter Up to Speed: ", speedSet);
	}

}

// Make this return true when this Command no longer needs to run execute()
bool ShootBoulder::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ShootBoulder::End()
{
	speedSet = false;
	shooter->StopShooterMotors();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShootBoulder::Interrupted()
{
	End();
}

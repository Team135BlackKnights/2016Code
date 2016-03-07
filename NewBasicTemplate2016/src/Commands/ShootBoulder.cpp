#include "ShootBoulder.h"

ShootBoulder::ShootBoulder()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(shooter.get());
	encoderVelocity = 0;

	timer.reset(new Timer());
	timeWait = 0;
	timerStarted = false;
}

// Called just before this Command runs the first time
void ShootBoulder::Initialize()
{
	//shooter->ZeroAllEncoders();
	timer->Reset();
	timeWait = Preferences::GetInstance()->GetFloat("ShooterWaitTime",3.5f);
}

// Called repeatedly when this Command is scheduled to run
void ShootBoulder::Execute()
{
	//encoderVelocity = shooter->GetEncoderVelocity(Shooter::TWO_WHEEL_SHOOTER_MOTOR);

	shooter->DriveShooterMotors(Shooter::OUT);

	//if (encoderVelocity >= setEncoderVelocity) {
		//SmartDashboard::PutBoolean("Shooter Up to Speed: ", true);

		if (!timerStarted) {
			timer->Reset();
			timer->Start();
			timerStarted = true;
		}
		else if (timer->Get() >= timeWait) {
			shooter->DriveKicker(Shooter::KICKER_KICKED);
		}
	//}
	//else
		//SmartDashboard::PutBoolean("Shooter Up to Speed: ", false);

}

// Make this return true when this Command no longer needs to run execute()
bool ShootBoulder::IsFinished()
{
	return timer->Get() >= timeWait + 2;
}

// Called once after isFinished returns true
void ShootBoulder::End()
{
	shooter->StopShooterMotors();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShootBoulder::Interrupted()
{
	End();
}

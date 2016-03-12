#include "ShootBoulder.h"

ShootBoulder::ShootBoulder()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(shooter.get());
	encoderVelocity = 0;

	timer.reset(new Timer());
	timeWait = 0;
}

// Called just before this Command runs the first time
void ShootBoulder::Initialize()
{
	//shooter->ZeroAllEncoders();
	timer->Reset();
	timeWait = Preferences::GetInstance()->GetFloat("ShooterWaitTime",1.0f);
}

// Called repeatedly when this Command is scheduled to run
void ShootBoulder::Execute()
{
	shooter->DriveShooterMotors(Shooter::OUT);

	if (shooter->ShooterUpToSpeed()) {
		//SmartDashboard::PutBoolean("Shooter Up to Speed: ", true);

		if (!timerStarted) {
			timer->Reset();
			timer->Start();
			timerStarted = true;
		}
	}

	if (timer->Get() > timeWait && timerStarted == true) {
		shooter->DriveKicker(Shooter::KICKER_KICKED);
	}

}

// Make this return true when this Command no longer needs to run execute()
bool ShootBoulder::IsFinished()
{
	return timer->Get() >= timeWait + 0.5D;
}

// Called once after isFinished returns true
void ShootBoulder::End()
{
	shooter->StopShooterMotors();
	shooter->DriveKicker(Shooter::KICKER_RESET);
	timer->Stop();
	timer->Reset();
	timerStarted = false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShootBoulder::Interrupted()
{
	End();
}

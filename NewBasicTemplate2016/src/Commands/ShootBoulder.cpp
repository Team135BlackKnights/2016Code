#include "ShootBoulder.h"

ShootBoulder::ShootBoulder()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(shooter.get());
	encoderVelocity = 0;

	timer.reset(new Timer());
}

// Called just before this Command runs the first time
void ShootBoulder::Initialize()
{
	//shooter->ZeroAllEncoders();
	timer->Reset();
}

// Called repeatedly when this Command is scheduled to run
void ShootBoulder::Execute()
{
	shooter->DriveShooterMotors(Shooter::OUT);

	if (shooter->ShooterUpToSpeed()) {
		SmartDashboard::PutBoolean("Shooter Up to Speed: ", true);

		if (!timerStarted) {
			timer->Reset();
			timer->Start();
			timerStarted = true;
		}
	}
	else
		SmartDashboard::PutBoolean("Shooter Up to Speed: ", false);

	if (timer->Get() > timeWait) {
		shooter->DriveKicker(Shooter::KICKER_KICKED);
		shooter->StopShooterMotors();
	}

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

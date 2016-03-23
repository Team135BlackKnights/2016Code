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
	timeWait = Preferences::GetInstance()->GetFloat("ShooterWaitTime",1.0f);
	//upToSpeed = false;
}

// Called repeatedly when this Command is scheduled to run
void ShootBoulder::Execute()
{
	//encoderVelocity = shooter->GetEncoderVelocity();

	shooter->DriveShooterMotors(Shooter::OUT);

	std::cout << "time revved" << timer->Get();
	//if (timer->Get() > timeWait) {
	if(shooter->GetShooterTrackerPeriod() >= Shooter::SHOOTER_TRACKER_SETPOINT){
		timer->Start();
		shooter->DriveKicker(Shooter::KICKER_KICKED);
	}

	/*if (shooter->ShooterUpToSpeed() && upToSpeed == false) {
		shooter->DriveKicker(Shooter::KICKER_KICKED);
		initialTimerValue = timer->Get();
		finalTimerValue = initialTimerValue + .50f;
	} */

}

// Make this return true when this Command no longer needs to run execute()
bool ShootBoulder::IsFinished()
{
	return timer->Get() >= 3.0f;
	//return (upToSpeed && finalTimerValue >= timer->Get());
}

// Called once after isFinished returns true
void ShootBoulder::End()
{
	shooter->StopShooterMotors();
	shooter->DriveKicker(Shooter::KICKER_RESET);
	timer->Stop();
	timer->Reset();
	timerStarted = false;
	//upToSpeed = false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShootBoulder::Interrupted()
{
	End();
}

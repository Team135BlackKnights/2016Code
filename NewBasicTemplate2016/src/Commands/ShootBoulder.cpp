#include "ShootBoulder.h"

ShootBoulder::ShootBoulder()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(shooter.get());

	timer.reset(new Timer());
	timeWait = TIMEOUT;
	timerStarted = false;
}

// Called just before this Command runs the first time
void ShootBoulder::Initialize()
{
	//shooter->ZeroAllEncoders();
	timer->Reset();
	//timeWait = Preferences::GetInstance()->GetFloat("ShooterWaitTime",1.0f);
	timer->Start();
	//upToSpeed = false;
}

// Called repeatedly when this Command is scheduled to run
void ShootBoulder::Execute()
{
	//encoderVelocity = shooter->GetEncoderVelocity();

	shooter->DriveShooterMotors(Shooter::OUT);

	std::cout << "time revved" << timer->Get();
	//if (timer->Get() > timeWait) {
	if(shooter->ShooterUpToSpeed() && arm->ArmPosIsGood()){
		timeWait = timer->Get();
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
	return timer->Get() >= timeWait + 1.5D;
	//return (upToSpeed && finalTimerValue >= timer->Get());
}

// Called once after isFinished returns true
void ShootBoulder::End()
{
	shooter->StopShooterMotors();
	shooter->DriveKicker(Shooter::KICKER_RESET);
	arm->ArmPosIsGood(false);
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

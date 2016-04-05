#include "DriveShooter.h"

DriveShooter::DriveShooter()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(shooter.get());

	timer.reset(new Timer());

	setTimerValue = 0;
}

// Called just before this Command runs the first time
void DriveShooter::Initialize()
{
	shooter->DriveKicker(Shooter::KICKER_RESET);
	shooter->BasedTimeCreateFileName();
	shooter->OpenFile();
	shooter->LogShooterTrackerValueHeader();
	timer->Reset();
}

// Called repeatedly when this Command is scheduled to run
void DriveShooter::Execute()
{
	float power = 0;
	//shootPower = oi->GetStickSlider(oi->manipulator->CONTROL_SHOOTER_POWER_SLIDER);//Preferences::GetInstance()->GetFloat("Shooter Power", motorPower);
	if (oi->GetButton(oi->manipulator->CONTROL_SHOOTER_OUT[STICK], oi->manipulator->CONTROL_SHOOTER_OUT[BUTTON])) {
		//oi->CONTROL_SHOOT[0], oi->CONTROL_SHOOT[1]))
		power = shootPower * Shooter::OUT;
		startTracking = true;
	}
	else if (oi->GetButton(oi->manipulator->CONTROL_SHOOTER_IN[STICK], oi->manipulator->CONTROL_SHOOTER_IN[BUTTON])) {//oi->CONTROL_COLLECTION_IN[0], oi->CONTROL_COLLECTION_IN[1]))
		if (!oi->GetButton(oi->manipulator->CONTROL_SHOOTER_INTAKE_OVERRIDE[STICK], oi->manipulator->CONTROL_SHOOTER_INTAKE_OVERRIDE[BUTTON]))
				power = Preferences::GetInstance()->GetFloat("CollectPower", .7f) * Shooter::IN;
		else
			power = 1.0f * Shooter::IN;
	}
	else {
		continueShooterTracking = false;
	}
	shooter->DriveShooterMotors(power);

	//if (oi->GetButton(oi->manipulator->CONTROL_SHOOTER_KICKER_KICK[STICK], oi->manipulator->CONTROL_SHOOTER_KICKER_KICK[BUTTON]))
	if (oi->IsPressed(oi->manipulator->CONTROL_SHOOTER_KICKER_KICK))
		shooter->DriveKicker(Shooter::KICKER_KICKED);
	else //if (oi->GetButton(oi->manipulator->CONTROL_SHOOTER_KICKER_RESET[STICK], oi->manipulator->CONTROL_SHOOTER_KICKER_RESET[BUTTON]))
		shooter->DriveKicker(Shooter::KICKER_RESET);

	/*
	if (oi->GetButton(OI::MANIP, 12))
		shooter->DriveUnstucker(Shooter::KICKER_KICKED);
	else //if (oi->GetButton(oi->manipulator->CONTROL_SHOOTER_KICKER_RESET[STICK], oi->manipulator->CONTROL_SHOOTER_KICKER_RESET[BUTTON]))
	*/

	shooterTrackerValue = shooter->GetShooterTrackerPeriod();

	if (startTracking) {
		timer->Reset();
		timer->Start();
		continueShooterTracking = true;
		timerStarted = true;
	}
	if (continueShooterTracking) {
		shooter->LogOneEncoderValue(timer->Get(), shooterTrackerValue);
		startTracking  = false;
		//if (shooterTrackerValue <= 70 && timer->Get() > 3) {
			//continueShooterTracking = false;
		//}
	}
	else if (continueShooterTracking == false && timerStarted == true) {
		shooter->CloseFile();
		timer->Stop();
		timer->Reset();
		timerStarted = false;
	}

	std::cout << "Shooter Tracker Value: " << shooterTrackerValue << std::endl;
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
	shooter->CloseFile();
	timer->Stop();
	timer->Reset();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveShooter::Interrupted()
{
	this->End();
}

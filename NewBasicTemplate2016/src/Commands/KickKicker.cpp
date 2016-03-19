#include "KickKicker.h"

KickKicker::KickKicker()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	timer.reset(new Timer());
	timer->Start();
}

// Called just before this Command runs the first time
void KickKicker::Initialize()
{
	timer->Reset();
	done = false;
}

// Called repeatedly when this Command is scheduled to run
void KickKicker::Execute()
{
	std::cout << "Timer timer timer timer";
	std::cout << "timer" << timer->Get() << std::endl;
	if (timer->Get() < 500)
			shooter.get()->DriveKicker(Shooter::KICKER_KICKED);
	else //if (oi->GetButton(oi->manipulator->CONTROL_SHOOTER_KICKER_RESET[STICK], oi->manipulator->CONTROL_SHOOTER_KICKER_RESET[BUTTON]))
	{
		shooter.get()->DriveKicker(Shooter::KICKER_RESET);
		done = true;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool KickKicker::IsFinished()
{
	return done;
}

// Called once after isFinished returns true
void KickKicker::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void KickKicker::Interrupted()
{

}

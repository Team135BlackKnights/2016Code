#include <Commands/WaitTime.h>

WaitTime::WaitTime(float time)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	this->time = time;
	this->timer.reset(new Timer());
}

// Called just before this Command runs the first time
void WaitTime::Initialize()
{
	this->timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void WaitTime::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool WaitTime::IsFinished()
{
	return this->timer->HasPeriodPassed(this->time);
}

// Called once after isFinished returns true
void WaitTime::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WaitTime::Interrupted()
{

}

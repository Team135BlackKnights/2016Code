#include "ChangeDriver.h"

ChangeDriver::ChangeDriver(Driver* driver)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	this->driver = driver;

}

// Called just before this Command runs the first time
void ChangeDriver::Initialize()
{
	oi->UpdateDriver(driver);
}

// Called repeatedly when this Command is scheduled to run
void ChangeDriver::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ChangeDriver::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ChangeDriver::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ChangeDriver::Interrupted()
{

}

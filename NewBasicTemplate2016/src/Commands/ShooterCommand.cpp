#include "ShooterCommand.h"

ShooterCommand::ShooterCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ShooterCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ShooterCommand::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ShooterCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ShooterCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterCommand::Interrupted()
{

}

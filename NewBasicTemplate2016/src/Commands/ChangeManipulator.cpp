#include "ChangeManipulator.h"

ChangeManipulator::ChangeManipulator(Manipulator* manipulator, bool updateButtons)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	this->manipulator = manipulator;
	this->updateButtons = updateButtons;
}

// Called just before this Command runs the first time
void ChangeManipulator::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void ChangeManipulator::Execute()
{
	oi->UpdateManipulator(manipulator, updateButtons);
}

// Make this return true when this Command no longer needs to run execute()
bool ChangeManipulator::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ChangeManipulator::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ChangeManipulator::Interrupted()
{

}

#include "DriveCollection.h"

DriveCollection::DriveCollection(bool PosNeg)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(collection.get());

	direction = PosNeg ? 1: -1;
}

// Called just before this Command runs the first time
void DriveCollection::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveCollection::Execute()
{
	collection->PowerCollection(motorPower * direction);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveCollection::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveCollection::End()
{
	collection->PowerCollection(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveCollection::Interrupted()
{
	End();
}

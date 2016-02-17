#include "DriveCollection.h"

DriveCollection::DriveCollection()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(collection.get());
}

// Called just before this Command runs the first time
void DriveCollection::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveCollection::Execute()
{
	float power = 0;
	if (oi->GetButton(oi->CONTROL_COLLECTION_IN[0], oi->CONTROL_COLLECTION_IN[1]))
		power = motorPower * Collection::IN;
	else 	if (oi->GetButton(oi->CONTROL_COLLECTION_OUT[0], oi->CONTROL_COLLECTION_OUT[1]))
		power = motorPower * Collection::OUT;
	collection->PowerCollection(motorPower);
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

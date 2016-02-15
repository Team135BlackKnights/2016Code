#include "Collection.h"
#include "../RobotMap.h"

Collection::Collection() :
		Subsystem("Collection")
{
	collectionMotor.reset(new VictorSP(MOTOR_COLLECTION));
}

void Collection::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}


void Collection::PowerCollection(double motorPower) {
	collectionMotor->Set(motorPower);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

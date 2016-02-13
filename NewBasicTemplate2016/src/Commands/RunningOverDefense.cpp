#include "RunningOverDefense.h"

RunningOverDefense::RunningOverDefense(TypeOfMethod typeOfMethod)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(serialCommunication.get());
	leftSonarDistance = 0;
	rightSonarDistance = 0;
	lightValueReceived = 0;
	this->typeOfMethod = typeOfMethod;

}

// Called just before this Command runs the first time
void RunningOverDefense::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void RunningOverDefense::Execute()
{
	leftSonarDistance = serialCommunication->GetSerialValues(SerialCommunication::LEFT_SONAR_VALUE);
	rightSonarDistance = serialCommunication->GetSerialValues(SerialCommunication::RIGHT_SONAR_VALUE);
	lightValueReceived = serialCommunication->GetSerialValues(SerialCommunication::LIGHT_SENSOR_VALUE);
}

// Make this return true when this Command no longer needs to run execute()
bool RunningOverDefense::IsFinished()
{

}

// Called once after isFinished returns true
void RunningOverDefense::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunningOverDefense::Interrupted()
{

}

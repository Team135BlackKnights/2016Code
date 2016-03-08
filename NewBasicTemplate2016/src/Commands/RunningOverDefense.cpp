#include "RunningOverDefense.h"

RunningOverDefense::RunningOverDefense()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(analogSensors.get());
}

// Called just before this Command runs the first time
void RunningOverDefense::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void RunningOverDefense::Execute()
{
	leftSonarDistance = analogSensors->GetSonarDistance(ANALOG_LEFT_SONAR_PORT);
	rightSonarDistance = analogSensors->GetSonarDistance(ANALOG_RIGHT_SONAR_PORT);

	std::cout << "Left: " << leftSonarDistance << " Right: " << rightSonarDistance << std::endl;
}

// Make this return true when this Command no longer needs to run execute()
bool RunningOverDefense::IsFinished()
{
	return false;
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

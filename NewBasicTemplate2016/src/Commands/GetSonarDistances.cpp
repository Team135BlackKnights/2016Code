#include "GetSonarDistances.h"

GetSonarDistances::GetSonarDistances()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(sonarSensors.get());

	timer.reset(new Timer());
}

// Called just before this Command runs the first time
void GetSonarDistances::Initialize()
{
	sonarSensors->BasedTimeCreateFileName();
	sonarSensors->OpenFile();
	sonarSensors->LogSonarDataHeader();
	timer->Reset();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void GetSonarDistances::Execute()
{
	leftSonarDistance = sonarSensors->GetDistanceInches(ANALOG_LEFT_SONAR_PORT);
	rightSonarDistance = sonarSensors->GetDistanceInches(ANALOG_RIGHT_SONAR_PORT);
	std::cout << "Left: " << leftSonarDistance << " Right: " << rightSonarDistance << std::endl;

	sonarSensors->LogTwoValues(timer->Get(), leftSonarDistance, rightSonarDistance);
}

// Make this return true when this Command no longer needs to run execute()
bool GetSonarDistances::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void GetSonarDistances::End()
{
	sonarSensors->CloseFile();
	timer->Stop();
	timer->Reset();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GetSonarDistances::Interrupted()
{
	this->End();
}

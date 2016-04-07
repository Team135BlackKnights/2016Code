#include "SerialCommunicationTesting.h"

SerialCommunicationTesting::SerialCommunicationTesting()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(serialCommunication.get());
	Requires(shooter.get());
	Requires(sonarSensors.get());
}

// Called just before this Command runs the first time
void SerialCommunicationTesting::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void SerialCommunicationTesting::Execute()
{
	//shooterTrackerValue = shooter->GetShooterTrackerPeriod();
	//serialCommunication->SendSerialShooterTrackerValue(shooterTrackerValue);

	sonarDistanceValue = sonarSensors->GetDistanceInches(ANALOG_LEFT_SONAR_PORT);
	serialCommunication->SendSonarDistanceValue(sonarDistanceValue);
}

// Make this return true when this Command no longer needs to run execute()
bool SerialCommunicationTesting::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void SerialCommunicationTesting::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SerialCommunicationTesting::Interrupted()
{

}

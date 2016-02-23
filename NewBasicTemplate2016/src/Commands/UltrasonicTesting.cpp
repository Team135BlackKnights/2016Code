#include "UltrasonicTesting.h"

UltrasonicTesting::UltrasonicTesting()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(analogSensors.get());
	leftSonarDistance = 0;
	rightSonarDistance = 0;
	lightSensorDistance = 0;
	//  i = 1;
}

// Called just before this Command runs the first time
void UltrasonicTesting::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void UltrasonicTesting::Execute()
{
	leftSonarDistance = analogSensors->GetSonarDistance(LEFT_SONAR_ANALOG_PORT);
	rightSonarDistance = analogSensors->GetSonarDistance(RIGHT_SONAR_ANALOG_PORT);
	lightSensorDistance = analogSensors->GetLightValue();

	std::cout << "Left: " << leftSonarDistance <<  "  " << "Right: " << rightSonarDistance << "  " << "Light: " << lightSensorDistance << std::endl;
	//  if (i % 10 == 0) {
	/*serialCommunication->ReadSerialValues();

	leftSonarDistance = serialCommunication->GetSerialValues(SerialCommunication::LEFT_SONAR_VALUE);
	rightSonarDistance = serialCommunication->GetSerialValues(SerialCommunication::RIGHT_SONAR_VALUE);
	lightSensorDistance = serialCommunication->GetSerialValues(SerialCommunication::LIGHT_SENSOR_VALUE);

	//  SmartDashboard::PutString("LEFT SONAR", data); */

}

// Make this return true when this Command no longer needs to run execute()
bool UltrasonicTesting::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void UltrasonicTesting::End()
{
	//leftSonarDistance = serialCommunication->StopSerialCommunicationAndReturnLastValue(SerialCommunication::LEFT_SONAR_VALUE);
	//rightSonarDistance = serialCommunication->StopSerialCommunicationAndReturnLastValue(SerialCommunication::RIGHT_SONAR_VALUE);
	//lightSensorDistance = serialCommunication->StopSerialCommunicationAndReturnLastValue(SerialCommunication::LIGHT_SENSOR_VALUE);


	//std::cout << "Left: " << leftSonarDistance <<  "  " << "Right: " << rightSonarDistance << "Light: " << lightSensorDistance << std::endl;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UltrasonicTesting::Interrupted()
{
	End();
}

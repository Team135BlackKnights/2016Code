#include "SonarSensors.h"
#include "../RobotMap.h"
#include "Commands/GetSonarDistances.h"

SonarSensors::SonarSensors() :
	PIDLogging("SonarSensors", "/home/lvuser/", numMotors, radius)
{
	leftSonar.reset(new AnalogInput(ANALOG_LEFT_SONAR_PORT));
	rightSonar.reset(new AnalogInput(ANALOG_RIGHT_SONAR_PORT));
}

void SonarSensors::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	//SetDefaultCommand(new GetSonarDistances());
}

float SonarSensors::GetDistanceInches(int analogPort) {
	if (analogPort == ANALOG_LEFT_SONAR_PORT) {
		return ((float)(leftSonar->GetVoltage()/VOLTS_PER_INCH));
	}
	else if (analogPort == ANALOG_RIGHT_SONAR_PORT) {
		return ((float)(rightSonar->GetVoltage()/VOLTS_PER_INCH));
	}
	else {
		return 0.0f;
	}
}

bool SonarSensors::LeftSonarOverDefense() {
	float leftSonarDistance = GetDistanceInches(ANALOG_LEFT_SONAR_PORT);
	if (leftSonarDistance <= SONAR_DISTANCE_OVER_DEFENSE && firstCross == false) {
		firstCross = true;
		return false;
	}
	else if (leftSonarDistance >= SONAR_DISTANCE_OVER_DEFENSE && firstCross) {
		return true;
	}
	else {
		return false;
	}
	//return (sonarDistance >= SONAR_DISTANCE_OVER_DEFENSE ? true : false);
}

bool SonarSensors::RightSonarOverDefense() {
	float rightSonarDistance = GetDistanceInches(ANALOG_RIGHT_SONAR_PORT);
	if (rightSonarDistance <= SONAR_DISTANCE_OVER_DEFENSE && firstCross == false) {
		firstCross = true;
		return false;
	}
	else if (rightSonarDistance >= SONAR_DISTANCE_OVER_DEFENSE && firstCross) {
		return true;
	}
	else {
		return false;
	}
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

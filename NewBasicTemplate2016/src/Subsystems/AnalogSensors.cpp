#include "AnalogSensors.h"
#include "../RobotMap.h"

AnalogSensors::AnalogSensors() :
		Subsystem("ExampleSubsystem")
{
	leftSonar.reset(new AnalogInput(ANALOG_LEFT_SONAR_PORT));
	rightSonar.reset(new AnalogInput(ANALOG_RIGHT_SONAR_PORT));
	lightSensor.reset(new AnalogInput(ANALOG_LIGHT_SENSOR_PORT));
}

void AnalogSensors::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

//  Input the Analog Sonar Port for which the sonar is plugged into
//  in order to get the value for either the left or right sonar
float AnalogSensors::GetSonarDistance(int sonarAnalogPort) {
	if (sonarAnalogPort == ANALOG_LEFT_SONAR_PORT) {
		leftSonarDistance = (leftSonar->GetVoltage()/CONVERSION_FACTOR_VOLTAGE_TO_INCHES_SONAR);
		return leftSonarDistance;
	}

	else if (sonarAnalogPort == ANALOG_RIGHT_SONAR_PORT) {
		rightSonarDistance = (rightSonar->GetVoltage()/CONVERSION_FACTOR_VOLTAGE_TO_INCHES_SONAR);
		return rightSonarDistance;
	}
	else {
		return 0.0f;
	}
}

int AnalogSensors::GetLightValue() {
	return lightSensor->GetValue();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

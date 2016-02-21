#include "AnalogSensors.h"
#include "../RobotMap.h"
#include "Commands/UltrasonicTesting.h"

AnalogSensors::AnalogSensors() :
		Subsystem("ExampleSubsystem")
{
	leftSonar.reset(new AnalogInput(LEFT_SONAR_ANALOG_PORT));
	rightSonar.reset(new AnalogInput(RIGHT_SONAR_ANALOG_PORT));
	light.reset(new AnalogInput(LIGHT_ANALOG_PORT));
}

void AnalogSensors::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new UltrasonicTesting());
}

//  Based off of Port Number
float AnalogSensors::GetSonarDistance(int rightOrLeft) {
	if (rightOrLeft == LEFT_SONAR_ANALOG_PORT) {
		//  Value for Left Sonar Sensor
		return leftSonar->GetValue();
	}
	else {
		return rightSonar->GetValue();
	}
}

int AnalogSensors::GetLightValue() {
	return light->GetValue();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

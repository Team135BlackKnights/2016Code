#include "AnalogSensors.h"
#include "../RobotMap.h"
#include "Commands/UltrasonicTesting.h"

AnalogSensors::AnalogSensors() :
		Subsystem("ExampleSubsystem")
{
	leftSonar.reset(new AnalogInput(LEFT_SONAR_ANALOG_PORT));
	rightSonar.reset(new AnalogInput(RIGHT_SONAR_ANALOG_PORT));
	light.reset(new AnalogInput(LIGHT_ANALOG_PORT));

	leftDistanceInches = 0;
	rightDistanceInches = 0;
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
		leftDistanceInches = leftSonar->GetVoltage()/(VOLTS_PER_INCH);
		return leftDistanceInches;
	}
	else {
		rightDistanceInches = rightSonar->GetVoltage()/(VOLTS_PER_INCH);
		return rightDistanceInches;
	}
}

int AnalogSensors::GetLightValue() {
	return light->GetValue();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

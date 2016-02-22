#include "AnalogSensors.h"
#include "../RobotMap.h"
#include "Commands/UltrasonicTesting.h"

AnalogSensors::AnalogSensors() :
		Subsystem("ExampleSubsystem")
{
	//leftSonar.reset(new AnalogInput(LEFT_SONAR_ANALOG_PORT));
	//rightSonar.reset(new AnalogInput(RIGHT_SONAR_ANALOG_PORT));

	leftSonar.reset(new PWM(LEFT_SONAR_PWM_PORT));
	rightSonar.reset(new PWM(RIGHT_SONAR_PWM_PORT));
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
//  Left is 0
//  Right is 1
float AnalogSensors::GetSonarDistanceLV(int rightOrLeft) {
	if (rightOrLeft == LEFT_SONAR_PWM_PORT) {
		//  Value for Left Sonar Sensor
		leftDistanceInches = leftSonar->GetRaw()/(PWM_CONVERT_TO_INCHES_CONVERT);
			return leftDistanceInches;
	}
	else {
		//  Value for Right Sonar Sensor
		rightDistanceInches = rightSonar->GetRaw()/(PWM_CONVERT_TO_INCHES_CONVERT);
		return rightDistanceInches;
	}
}

//  Not too accurate of values
float AnalogSensors::GetSonarDistanceHRLV(int rightOrLeft) {
	return 5;
	/*if (rightOrLeft == LEFT_SONAR_PWM_PORT) {
		//  Value for Left Sonar Sensor
		float leftDistanceInMillimeters = ((leftSonar->GetAverageVoltage()/(VOLTS_PER_5MM_HRLV))*5);
		float leftDistanceInCentimeters = leftDistanceInMillimeters * 10;
		leftDistanceInches = (leftDistanceInCentimeters/2.54);
		return leftDistanceInches;
	}
	else {
		//  Value for Right Sonar Sensor
		float rightDistanceInMillimeters = ((rightSonar->GetAverageVoltage()/(VOLTS_PER_5MM_HRLV))*5);
		float rightDistanceInCentimeters = rightDistanceInMillimeters * 10;
		rightDistanceInches = (rightDistanceInCentimeters/2.54);
		return rightDistanceInches;
	} */
}

int AnalogSensors::GetLightValue() {
	return light->GetValue();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

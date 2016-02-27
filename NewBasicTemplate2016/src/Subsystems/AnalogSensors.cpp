#include "AnalogSensors.h"
#include "../RobotMap.h"
#include "Commands/UltrasonicTesting.h"

AnalogSensors::AnalogSensors() :
		Subsystem("AnalogSensors")
{
	leftSonar.reset(new AnalogInput(LEFT_SONAR_ANALOG_PORT));
	rightSonar.reset(new AnalogInput(RIGHT_SONAR_ANALOG_PORT));
	light.reset(new AnalogInput(LIGHT_ANALOG_PORT));

	leftDistanceInches = 0;
	rightDistanceInches = 0;

	lightValue = 0;

	passedFirstRamp = false;
	startUsingUltrasonicSensors = false;

	initialEncoderPosition = 0;
	finalEncoderPosition = 0;
}

void AnalogSensors::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	//SetDefaultCommand(new UltrasonicTesting());
}

//  Based off of Port Number
//  Left is 0
//  Right is 1
float AnalogSensors::GetSonarDistance(int rightOrLeft) {
	if (rightOrLeft == LEFT_SONAR_ANALOG_PORT) {
		//  Value for Left Sonar Sensor
		leftDistanceInches = leftSonar->GetVoltage()/(VOLTS_PER_INCH_LV);
		return leftDistanceInches;
	}
	else {
		//  Value for Right Sonar Sensor
		rightDistanceInches = rightSonar->GetVoltage()/(VOLTS_PER_INCH_LV);
		return rightDistanceInches;
	}
}

int AnalogSensors::GetLightValue() {
	lightValue = light->GetValue();
	return lightValue;
}

bool AnalogSensors::OverDefense(DEFENSE_METHOD typeOfDefense, int encoderPosition) {
	leftDistanceInches = GetSonarDistance(LEFT_SONAR_ANALOG_PORT);
	rightDistanceInches = GetSonarDistance(RIGHT_SONAR_ANALOG_PORT);
	lightValue = GetLightValue();

	switch (typeOfDefense) {
	case CASE_ROUGH_TERRAIN:
	case CASE_MOAT:
	case CASE_RAMPARTS:
	case CASE_ROCKWALL:
		if (leftDistanceInches > LEFT_SONAR_BARRIER_DISTANCE && rightDistanceInches > RIGHT_SONAR_BARRIER_DISTANCE) {
			if (passedFirstRamp)
				return true;
		}
		else {
			passedFirstRamp = true;
		}

		return false;
	break;

	case CASE_LOW_BAR:
		if (rightDistanceInches > RIGHT_SONAR_BARRIER_DISTANCE) {
			if (passedFirstRamp)
					return true;
		}
		else {
			passedFirstRamp = true;
		}

		return false;
	break;

	default:
		return false;
	break;
	}


	//  With Light Sensors
	/*switch (typeOfMethod) {
	case CASE_ROUGH_TERRAIN:
	case CASE_MOAT:
	case CASE_RAMPARTS:
	case CASE_ROCKWALL:
		if (lightValue > OVER_DEFENSE_LIGHT_VALUE && passedFirstRamp == false) {
			initialEncoderPosition = encoderPosition;
			finalEncoderPosition = initialEncoderPosition + addOnEncoderPosition;
			passedFirstRamp = true;
			return false;
		}
		else if (lightValue > OVER_DEFENSE_LIGHT_VALUE && passedFirstRamp == true && encoderPosition > finalEncoderPosition) {
			startUsingUltrasonicSensors = true;
			return false;
		}
		else if (startUsingUltrasonicSensors == true && leftDistanceInches > LEFT_SONAR_BARRIER_DISTANCE && rightDistanceInches > RIGHT_SONAR_BARRIER_DISTANCE) {
			return true;
		}
		else {
			return false;
		}
		break;
	case CASE_LOW_BAR:
		if (lightValue > OVER_DEFENSE_LIGHT_VALUE && passedFirstRamp == false) {
			initialEncoderPosition = encoderPosition;
			finalEncoderPosition = initialEncoderPosition + addOnEncoderPosition;
			passedFirstRamp = true;
			return false;
		}
		else if (lightValue > OVER_DEFENSE_LIGHT_VALUE && passedFirstRamp == true && encoderPosition > finalEncoderPosition) {
			startUsingUltrasonicSensors = true;
			return false;
		}
		else if (startUsingUltrasonicSensors == true && rightDistanceInches > RIGHT_SONAR_BARRIER_DISTANCE) {
			return true;
		}
		else {
			return false;
		}
		break;
	} */
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

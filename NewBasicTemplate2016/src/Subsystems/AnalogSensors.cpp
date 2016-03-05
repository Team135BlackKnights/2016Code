#include "AnalogSensors.h"
#include "Commands/UltrasonicTesting.h"

AnalogSensors::AnalogSensors() :
		Subsystem("AnalogSensors")
{
	//  Declares the sonars and light sensors in their designated analog input port number
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
	SetDefaultCommand(new UltrasonicTesting());
}

//  Based off of the Analog Input Port Number
float AnalogSensors::GetSonarDistance(int rightOrLeft) {
	//  If you input the Left Sonar Analog Port Number into this function
	if (rightOrLeft == LEFT_SONAR_ANALOG_PORT) {
		//  Calculate the distance from the left sonar by converting voltage into inches
		leftDistanceInches = leftSonar->GetVoltage()/(VOLTS_PER_INCH_LV);
		return leftDistanceInches;
	}
	//  If you input the Right Sonar Analog Port Number into this function
	else if (RIGHT_SONAR_ANALOG_PORT) {
		//  Calculate the distance from the right sonar by converting voltage into inches
		rightDistanceInches = rightSonar->GetVoltage()/(VOLTS_PER_INCH_LV);
		return rightDistanceInches;
	}
	//  If you don't input either of those values
	else {
		//  Return 0.0
		return 0.0;
	}
}

//  Gets the Light Sensor Value and returns it
int AnalogSensors::GetLightValue() {
	lightValue = light->GetValue();
	return lightValue;
}

//  Function that will return true if the robot is over the Defense
//  This function is used in RunningOverDefense
bool AnalogSensors::OverDefense(DEFENSE_METHOD typeOfDefense, int encoderPosition) {
	//  Gets the values of the Sonars and Light Sensor for use in this function
	leftDistanceInches = GetSonarDistance(LEFT_SONAR_ANALOG_PORT);
	rightDistanceInches = GetSonarDistance(RIGHT_SONAR_ANALOG_PORT);
	lightValue = GetLightValue();

	//  Without Light Sensors

	//  Executes a case depending upon what enum value you input into this function
	switch (typeOfDefense) {
	//  All these four cases will execute the same function
	case CASE_ROUGH_TERRAIN:
	case CASE_MOAT:
	case CASE_RAMPARTS:
	case CASE_ROCKWALL:
	case CASE_CHEVAL_DE_FRISE:
		//  If the left and right sonars are getting values that assume the robot is out of the defenses
		if (leftDistanceInches > LEFT_SONAR_BARRIER_DISTANCE && rightDistanceInches > RIGHT_SONAR_BARRIER_DISTANCE) {
			//  If you have passed the first ramp, return true;  if not, return false
			if (passedFirstRamp)
				return true;
		}
		//  If the left and right sonars are getting values that assume the robot is still in the defense
		else {
			//  Then the robot is in the defense and has passed the first ramp
			passedFirstRamp = true;
		}
		//  Return false by default if you don't return true
		return false;
	break;

	case CASE_LOW_BAR:
		//  Low bar can only rely off of the right sonar and the left sonar will have a constant value
		//  The low bar is placed all the way to the left
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
	/*switch (typeOfDefense) {
	//  All four of these enums will run the same code
	case CASE_ROUGH_TERRAIN:
	case CASE_MOAT:
	case CASE_RAMPARTS:
	case CASE_ROCKWALL:
	case CASE_CHEVAL_DE_FRISE:
		//  If the light Value displays that the robot is on top of a ramp and on the defense
		if (lightValue > OVER_DEFENSE_LIGHT_VALUE && passedFirstRamp == false) {
			//  Then the robot has passed the first ramp
			passedFirstRamp = true;
			//  Record the robot's Drive Train encoder value and have the robot drive 36 inches before
			//  using the values of the sonars to determine if the robot is over the defense
			initialEncoderPosition = encoderPosition;
			finalEncoderPosition = initialEncoderPosition + addOnEncoderPosition;
			return false;
		}
		//  If the robot has passed the first ramp and the light value displays the robot is out of the defense
		else if (lightValue > OVER_DEFENSE_LIGHT_VALUE && passedFirstRamp == true && encoderPosition > finalEncoderPosition) {
			//  Start using the values for the sonars to determine whether the robot is over the defense
			startUsingUltrasonicSensors = true;
			return false;
		}
		//  If the sonars display values that show the robot is  over the obstacle, the robot is over the defense, so return true
		else if (startUsingUltrasonicSensors == true && leftDistanceInches > LEFT_SONAR_BARRIER_DISTANCE && rightDistanceInches > RIGHT_SONAR_BARRIER_DISTANCE) {
			return true;
		}
		else {
			//  If none of those statements above are true, the robot is not over the obstacle, so return false
			return false;
		}
		break;
	case CASE_LOW_BAR:
		//  Executes the same code as above, except only uses the right sonar
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

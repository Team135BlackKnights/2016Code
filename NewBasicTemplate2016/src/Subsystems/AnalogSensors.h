#ifndef AnalogSensors_H
#define AnalogSensors_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../RobotMap.h"

class AnalogSensors: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	std::unique_ptr<AnalogInput> leftSonar;
	std::unique_ptr<AnalogInput> rightSonar;
	std::unique_ptr<AnalogInput> light;

	float leftDistanceInches,
		  rightDistanceInches;

	int lightValue;

	static constexpr float VOLTS_PER_INCH_LV = 5.0f/512.0f;
	static constexpr float VOLTS_PER_5MM_HRLV = 5.0f/1024.0f;

	int typeOfMethod;

	static constexpr float COUNT = 64.0f;
	static constexpr float QUADRATURE_COUNT = 4.0f * COUNT;

	static constexpr float INCHES_TO_ENCODER_POSITION = QUADRATURE_COUNT/(12*M_PI);

	int encoderPosition;
	int initialEncoderPosition,
		finalEncoderPosition,
		addOnEncoderPosition = (LENGTH_OF_ROBOT * INCHES_TO_ENCODER_POSITION) + (24 * INCHES_TO_ENCODER_POSITION);

	static constexpr double leftSonarBarrierDistance = 22,
		   rightSonarBarrierDistance = 22,
		   overDefenseLightValue = 30;

	bool passedFirstRamp;



public:
	AnalogSensors();
	void InitDefaultCommand();
	float GetSonarDistance(int);
	int GetLightValue();
	bool OverDefense(int);

	static const int CASE_LIGHT = 0,
				     CASE_LEFT_AND_LIGHT = 1,
				     CASE_RIGHT_AND_LIGHT = 2,
				     CASE_LEFT_RIGHT_AND_LIGHT = 3;
};

#endif

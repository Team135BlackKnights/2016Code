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

	static constexpr float COUNT = 64.0f;
	static constexpr float QUADRATURE_COUNT = 4.0f * COUNT;

	static constexpr float INCHES_TO_ENCODER_POSITION = QUADRATURE_COUNT/(12*M_PI);

	int initialEncoderPosition,
		finalEncoderPosition,
		//  24 inches to travel after light sensor detects first light
		addOnEncoderPosition = 36 * INCHES_TO_ENCODER_POSITION;


	static constexpr double WIDTH_BETWEEN_BARRIERS = 50.5;

	//  The max distance the sonars can detect within the defense while the robot is straight
	static constexpr double LEFT_SONAR_BARRIER_DISTANCE = WIDTH_BETWEEN_BARRIERS - WIDTH_OF_ROBOT;
	static constexpr double RIGHT_SONAR_BARRIER_DISTANCE = WIDTH_BETWEEN_BARRIERS - WIDTH_OF_ROBOT;

	//  Still To be Determined
	static constexpr double OVER_DEFENSE_LIGHT_VALUE = 30;

	bool passedFirstRamp;
	bool startUsingUltrasonicSensors;



public:
	enum DEFENSE_METHOD {
		CASE_LOW_BAR = 0,
		CASE_ROUGH_TERRAIN = 1,
		CASE_MOAT = 2,
		CASE_RAMPARTS = 3,
		CASE_ROCKWALL = 4
	};

	AnalogSensors();
	void InitDefaultCommand();
	float GetSonarDistance(int);
	int GetLightValue();
	bool OverDefense(DEFENSE_METHOD, int);

	/*static const int CASE_LIGHT = 0,
				     CASE_LEFT_AND_LIGHT = 1,
				     CASE_RIGHT_AND_LIGHT = 2,
				     CASE_LEFT_RIGHT_AND_LIGHT = 3; */

};

#endif

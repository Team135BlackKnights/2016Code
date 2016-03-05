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

	//  Declaring the left and right Sonars in Analog Inputs on the RoboRIO
	std::unique_ptr<AnalogInput> leftSonar;
	std::unique_ptr<AnalogInput> rightSonar;

	//  Declaring the Light Sensor in an Analog Input slot on the RoboRIO
	std::unique_ptr<AnalogInput> light;

	float leftDistanceInches,
		  rightDistanceInches;

	int lightValue;

	//  Used to Convert Voltage into inches
	static constexpr float VOLTS_PER_INCH_LV = 5.0f/512.0f;

	static constexpr float COUNT = 64.0f;
	static constexpr float QUADRATURE_COUNT = 4.0f * COUNT;

	//  Used to convert inches to an encoder count
	//  Multiply this by the number of inches you want to move in order to get the desired encoder count
	static constexpr float INCHES_TO_ENCODER_POSITION = QUADRATURE_COUNT/(DIAMETER_OF_DRIVE_TRAIN_WHEELS*M_PI);

	int initialEncoderPosition,
		finalEncoderPosition;

	//  36 inches to travel after light sensor detects first light
	int addOnEncoderPosition = 36 * INCHES_TO_ENCODER_POSITION;


	// The distance between the barriers of the defenses
	static constexpr double WIDTH_BETWEEN_BARRIERS = 50.5;

	//  The max distance the sonars can detect within the defense while the robot is straight
	static constexpr double LEFT_SONAR_BARRIER_DISTANCE = WIDTH_BETWEEN_BARRIERS - WIDTH_OF_ROBOT;
	static constexpr double RIGHT_SONAR_BARRIER_DISTANCE = WIDTH_BETWEEN_BARRIERS - WIDTH_OF_ROBOT;

	//  Still To be Determined
	static constexpr double OVER_DEFENSE_LIGHT_VALUE = 30;

	bool passedFirstRamp;
	bool startUsingUltrasonicSensors;



public:
	//  Enum used in order to select which defense the robot will go over
	enum DEFENSE_METHOD {
		CASE_LOW_BAR = 0,
		CASE_ROUGH_TERRAIN = 1,
		CASE_MOAT = 2,
		CASE_RAMPARTS = 3,
		CASE_ROCKWALL = 4,
		CASE_CHEVAL_DE_FRISE = 5
	};

	AnalogSensors();
	void InitDefaultCommand();
	float GetSonarDistance(int);
	int GetLightValue();
	bool OverDefense(DEFENSE_METHOD, int);

};

#endif

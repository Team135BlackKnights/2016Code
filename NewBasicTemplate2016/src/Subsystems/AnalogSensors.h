#ifndef AnalogSensors_H
#define AnalogSensors_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "RobotMap.h"

class AnalogSensors: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	std::unique_ptr<AnalogInput> leftSonar;
	std::unique_ptr<AnalogInput> rightSonar;
	std::unique_ptr<AnalogInput> lightSensor;

	static constexpr float CONVERSION_FACTOR_VOLTAGE_TO_INCHES_SONAR = 5.0f/512.0f;

	float leftSonarDistance = 0,
		  rightSonarDistance = 0;

public:
	AnalogSensors();
	void InitDefaultCommand();

	float GetSonarDistance(int);
	int GetLightValue();
	//bool OvetrDefense(TYPE_OF_DEFENSE);
};

#endif

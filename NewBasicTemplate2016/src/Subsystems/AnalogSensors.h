#ifndef AnalogSensors_H
#define AnalogSensors_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class AnalogSensors: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	std::unique_ptr<AnalogInput> leftSonar;
	std::unique_ptr<AnalogInput> rightSonar;
	std::unique_ptr<AnalogInput> light;
public:
	AnalogSensors();
	void InitDefaultCommand();
	float GetSonarDistance(int);
	int GetLightValue();
};

#endif

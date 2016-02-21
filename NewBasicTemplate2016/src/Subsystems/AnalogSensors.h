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

	float leftDistanceInches,
		  rightDistanceInches;

	static constexpr float VOLTS_PER_INCH_LV = 5.0f/512.0f;
	static constexpr float VOLTS_PER_5MM_HRLV = 5.0f/1024.0f;
public:
	AnalogSensors();
	void InitDefaultCommand();
	float GetSonarDistanceLV(int);
	float GetSonarDistanceHRLV(int);
	int GetLightValue();
};

#endif

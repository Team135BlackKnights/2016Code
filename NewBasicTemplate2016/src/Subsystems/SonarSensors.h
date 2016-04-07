#ifndef SonarSensors_H
#define SonarSensors_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "PIDLogging.h"

class SonarSensors: public PIDLogging
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::unique_ptr<AnalogInput> leftSonar;
	std::unique_ptr<AnalogInput> rightSonar;

	static constexpr float VOLTS_PER_INCH = (5.0f/512.0f);
	//  Still needs to be determined
	static constexpr float SONAR_DISTANCE_OVER_DEFENSE = 30.0f;

	bool firstCross = false;
public:
	SonarSensors();
	void InitDefaultCommand();
	float GetDistanceInches(int);
	bool LeftSonarOverDefense();
	bool RightSonarOverDefense();
};

#endif

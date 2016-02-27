#ifndef RunningOverDefense_H
#define RunningOverDefense_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "RobotMap.h"
#include "AnalogSensors.h"

class RunningOverDefense: public CommandBase
{
private:

	double leftSonarDistance,
		   rightSonarDistance,
		   lightValueReceived;

	bool overDefense;

	std::unique_ptr<Timer> timer;

	double initialTimerValue,
		   setTimerValue,
		   waitTimerValue = .5;

	const double motorPower = .5D;

	int placer;

	int encoderPosition;;

public:
	RunningOverDefense(AnalogSensors::DEFENSE_METHOD);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

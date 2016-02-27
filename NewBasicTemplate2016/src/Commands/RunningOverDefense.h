#ifndef RunningOverDefense_H
#define RunningOverDefense_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "RobotMap.h"
#include "AnalogSensors.h"

class RunningOverDefense: public CommandBase
{
private:
	bool overDefense;

	const double motorPower = .5D;

	int encoderPosition;

	AnalogSensors::DEFENSE_METHOD typeOfDefense;

public:
	RunningOverDefense(AnalogSensors::DEFENSE_METHOD);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

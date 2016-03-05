#ifndef RunningOverDefense_H
#define RunningOverDefense_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "RobotMap.h"

class RunningOverDefense: public CommandBase
{
private:
	//  Declaring variables to be used in .cpp file
	//  These variables' uses are further explained in the .cpp file
	bool overDefense;

	const double motorPower = .5D;

	int encoderPosition;

	AnalogSensors::DEFENSE_METHOD typeOfDefense;

	double currentPositionOfArm,
		   desiredSPositionOfArm;

	bool armSet;

public:
	RunningOverDefense(AnalogSensors::DEFENSE_METHOD);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

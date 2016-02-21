#ifndef RunningOverDefense_H
#define RunningOverDefense_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Subsystems/SerialCommunication.h"
#include "RobotMap.h"

class RunningOverDefense: public CommandBase
{
private:

	double leftSonarDistance,
		   rightSonarDistance,
		   lightValueReceived;

	bool overDefense;

	int typeOfMethod;

	std::unique_ptr<Timer> timer;

	double initialTimerValue,
		   setTimerValue,
		   waitTimerValue = .5;

	const double motorPower = .8;

	int placer;

	int encoderPosition;;

public:
	RunningOverDefense(int);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

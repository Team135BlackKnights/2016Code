#ifndef PIDTesting_H
#define PIDTesting_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Subsystems/LogData.h"

class PIDTesting: public CommandBase
{
private:
	//int PortNumber = 2;

	//int PValue,
	//	IValue,
	//	DValue;

	//int power = .5;

	//double encoderValue;

	std::unique_ptr<Timer> timer;

	double timerValue;

	//std::string PIDFileName = "PID.csv";

public:
	PIDTesting();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

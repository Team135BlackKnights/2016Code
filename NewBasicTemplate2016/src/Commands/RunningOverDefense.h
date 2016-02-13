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

public:
	RunningOverDefense();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

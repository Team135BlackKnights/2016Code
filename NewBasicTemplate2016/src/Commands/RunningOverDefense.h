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

	TypeOfMethod typeOfMethod;

	bool overDefense;

public:
	RunningOverDefense(TypeOfMethod);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

#ifndef RunningOverDefense_H
#define RunningOverDefense_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Subsystems/SerialCommunication.h"

class RunningOverDefense: public CommandBase
{
private:

	double leftSonarDistance,
		   rightSonarDistance,
		   lightValueReceived;

	TypeOfMethod typeOfMethod;

public:
	RunningOverDefense(TypeOfMethod);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

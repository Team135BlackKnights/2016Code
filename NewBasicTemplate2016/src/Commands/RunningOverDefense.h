#ifndef RunningOverDefense_H
#define RunningOverDefense_H

#include "../CommandBase.h"
#include "WPILib.h"

class RunningOverDefense: public CommandBase
{
private:
	float leftSonarDistance = 0,
		  rightSonarDistance = 0,
		  lightValue = 0;
public:
	RunningOverDefense();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

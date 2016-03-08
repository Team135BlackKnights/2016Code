#ifndef AutomationOfArm_H
#define AutomationOfArm_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutomationOfArm: public CommandBase
{
private:
	double currentValue,
		   desiredValue,
		   startingValue,
		   angle;

	//double inchesHypotenuse;

	double motorPower = .8f;

public:
	AutomationOfArm();
	AutomationOfArm(double angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

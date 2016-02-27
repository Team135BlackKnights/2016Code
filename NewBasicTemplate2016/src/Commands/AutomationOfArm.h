#ifndef AutomationOfArm_H
#define AutomationOfArm_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutomationOfArm: public CommandBase
{
private:
	double currentValue,
		   desiredValue;

	//double inchesHypotenuse;

	double motorPower = .8;

	Arm::CONTROL_TYPE controlType;

public:
	AutomationOfArm(Arm::CONTROL_TYPE);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

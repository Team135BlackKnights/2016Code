#ifndef AutomationOfArm_H
#define AutomationOfArm_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutomationOfArm: public CommandBase
{
private:
	int currentArmEncoderValue;
	int desiredArmEncoderValue;

	double inchesHypotenuse;

	double motorPower = .8;

public:
	AutomationOfArm();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

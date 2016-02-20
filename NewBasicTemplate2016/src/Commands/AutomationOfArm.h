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

	double motorPowerUp = .2;
	double motorPowerDown = -.2;

public:
	AutomationOfArm(double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

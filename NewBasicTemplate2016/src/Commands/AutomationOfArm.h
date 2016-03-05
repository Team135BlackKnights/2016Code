#ifndef AutomationOfArm_H
#define AutomationOfArm_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutomationOfArm: public CommandBase
{
private:
	//  The currentValue will be equal to what the potentiometer or encoder value reads at the particular
	//  moment in time we are executing this command.  The desiredValue equals what the potentiometer or encoder
	//  value should be after some calculations
	double currentValue,
		   desiredValue;

	double motorPower = .8f;

public:
	AutomationOfArm();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

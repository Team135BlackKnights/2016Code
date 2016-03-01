#ifndef SetArmPosition_H
#define SetArmPosition_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Triggers/ResetEncoderFromLimitSwitch.h"

class SetArmPosition: public CommandBase
{
public:
	SetArmPosition(int position);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

#ifndef OverrideLimitSwitch_H
#define OverrideLimitSwitch_H

#include "../CommandBase.h"
#include "WPILib.h"

class OverrideLimitSwitch: public CommandBase
{
public:
	OverrideLimitSwitch();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

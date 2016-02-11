#ifndef RaiseAndLowerArm_H
#define RaiseAndLowerArm_H

#include "../CommandBase.h"
#include "WPILib.h"

class RaiseAndLowerArm: public CommandBase
{
public:
	RaiseAndLowerArm();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

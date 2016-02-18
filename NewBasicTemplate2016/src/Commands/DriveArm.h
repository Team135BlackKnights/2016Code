#ifndef RaiseAndLowerArm_H
#define RaiseAndLowerArm_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveArm: public CommandBase
{
public:
	DriveArm();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

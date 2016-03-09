#ifndef LiftHangFlipper_H
#define LiftHangFlipper_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveLiftHangFlipper: public CommandBase
{
public:
	DriveLiftHangFlipper();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

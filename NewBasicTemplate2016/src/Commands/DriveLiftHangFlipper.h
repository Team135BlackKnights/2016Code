#ifndef LiftHangFlipper_H
#define LiftHangFlipper_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveLiftHangFlipper: public CommandBase
{
private:
	float direction;
public:
	DriveLiftHangFlipper(float direction);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

#ifndef DriveLiftHangFlipper_H
#define DriveLiftHangFlipper_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveLiftHangFlipper: public CommandBase
{
private:
	float power;
public:
	DriveLiftHangFlipper(float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

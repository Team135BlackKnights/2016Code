#ifndef DriveLiftHangFlipper_H
#define DriveLiftHangFlipper_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveLiftHangFlipper: public CommandBase
{
private:
	float direction;
public:
	DriveLiftHangFlipper(bool);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

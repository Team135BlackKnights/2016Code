#ifndef RaiseArm_H
#define RaiseArm_H

#include "../CommandBase.h"
#include "WPILib.h"

class RaiseArm: public CommandBase
{
private:
	Timer* timer;
	const int TimeRaise = Preferences::GetInstance()->GetInt("raiseTime", 5);
public:
	RaiseArm();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

#ifndef Wait_H
#define Wait_H

#include "../CommandBase.h"
#include "WPILib.h"

class WaitTime: public CommandBase
{
private:
	float time;
	std::unique_ptr<Timer> timer;
public:
	WaitTime(float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

#ifndef Autonomous_H
#define Autonomous_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "OI.h"

class Autonomous: public CommandBase
{
private:
	bool IsDone = false;
public:
	Autonomous(int, int);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

#ifndef PIDTesting_H
#define PIDTesting_H

#include "../CommandBase.h"
#include "WPILib.h"

class PIDTesting: public CommandBase
{
public:
	PIDTesting();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

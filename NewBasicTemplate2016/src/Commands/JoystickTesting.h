#ifndef JoystickTesting_H
#define JoystickTesting_H

#include "../CommandBase.h"
#include "WPILib.h"

class JoystickTesting: public CommandBase
{
public:
	JoystickTesting();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

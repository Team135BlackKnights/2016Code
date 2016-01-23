#ifndef JoystickTesting_H
#define JoystickTesting_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "OI.h"
#include "DriveTrain.h"

class JoystickTesting: public CommandBase
{
private:
	double joystickX,
		   joystickY;

public:
	JoystickTesting();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

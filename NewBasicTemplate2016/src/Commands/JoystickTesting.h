#ifndef JoystickTesting_H
#define JoystickTesting_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "OI.h"
#include "RobotMap.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/LogData.h"

class JoystickTesting: public CommandBase
{
private:
	double joystickX,
		   joystickY;

	std::string joystickFileName = "joystick.csv";

public:
	JoystickTesting();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

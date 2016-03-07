#ifndef TurnRobotAngle_H
#define TurnRobotAngle_H

#include "../CommandBase.h"
#include "WPILib.h"

class TurnRobotAngle: public CommandBase
{
public:
	TurnRobotAngle();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

#ifndef MoveToShootingPosition_H
#define MoveToShootingPosition_H

#include "../CommandBase.h"
#include "WPILib.h"

class MoveToShootingPosition: public CommandBase
{
public:
	MoveToShootingPosition();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

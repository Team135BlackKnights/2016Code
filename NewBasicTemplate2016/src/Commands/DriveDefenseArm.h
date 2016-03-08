#ifndef DriveDefenseArm_H
#define DriveDefenseArm_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveDefenseArm: public CommandBase
{
public:
	DriveDefenseArm();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

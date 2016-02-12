#ifndef ChangeNeutralMode_H
#define ChangeNeutralMode_H

#include "../CommandBase.h"
#include "WPILib.h"

class ChangeNeutralMode: public CommandBase
{
public:
	ChangeNeutralMode(bool coast);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

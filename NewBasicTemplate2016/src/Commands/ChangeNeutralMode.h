#ifndef ChangeNeutralMode_H
#define ChangeNeutralMode_H

#include "../CommandBase.h"
#include "WPILib.h"

class ChangeNeutralMode: public CommandBase
{
private:
	bool mode;
public:
	ChangeNeutralMode(bool mode);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

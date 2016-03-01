#ifndef ChangeDriver_H
#define ChangeDriver_H

#include "../CommandBase.h"
#include "WPILib.h"

class ChangeDriver: public CommandBase
{
	Driver* driver;
public:
	ChangeDriver(Driver* driver);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

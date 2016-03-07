#ifndef ChangeDriver_H
#define ChangeDriver_H

#include "../CommandBase.h"
#include "WPILib.h"

class ChangeDriver: public CommandBase
{
	bool updateButtons;
public:
	ChangeDriver(Driver* driver, bool updateButtons=true);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

	Driver* driver;
};

#endif

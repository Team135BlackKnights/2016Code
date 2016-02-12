#ifndef DriveCollection_H
#define DriveCollection_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveCollection: public CommandBase
{
public:
	DriveCollection();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

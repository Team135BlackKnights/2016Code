#ifndef DriveCollection_H
#define DriveCollection_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveCollection: public CommandBase
{
private:
	float motorPower = 1.0f;
public:
	DriveCollection();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

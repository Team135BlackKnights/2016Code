#ifndef DriveCollection_H
#define DriveCollection_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveCollection: public CommandBase
{
private:
	double motorPower = .8;

	int direction;
public:
	DriveCollection(bool);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

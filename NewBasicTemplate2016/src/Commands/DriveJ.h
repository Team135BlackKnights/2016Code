#ifndef DriveTeleop_H
#define DriveTeleop_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveJ: public CommandBase
{
private:
	int index = 0;
public:
	DriveJ();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

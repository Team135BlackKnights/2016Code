#ifndef DriveTeleop_H
#define DriveTeleop_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveJ: public CommandBase
{
private:
	float ROTATION_MULTIPLICATION_CONSTANT = .75f;
	int index = 0;
	bool inverted;
public:
	DriveJ();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

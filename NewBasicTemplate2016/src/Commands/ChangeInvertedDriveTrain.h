#ifndef ChangeInvertedDriveTrain_H
#define ChangeInvertedDriveTrain_H

#include "../CommandBase.h"
#include "WPILib.h"

class ChangeInvertedDriveTrain: public CommandBase
{
protected:
	bool invert;
public:
	ChangeInvertedDriveTrain(bool invert);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

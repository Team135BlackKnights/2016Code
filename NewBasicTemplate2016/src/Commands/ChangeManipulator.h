#ifndef ChangeManipulator_H
#define ChangeManipulator_H

#include "../CommandBase.h"
#include "WPILib.h"

class ChangeManipulator: public CommandBase
{
	Manipulator* manipulator;
public:
	ChangeManipulator(Manipulator* manipulator);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
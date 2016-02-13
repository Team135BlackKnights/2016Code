#ifndef MoveFromCameraValue_H
#define MoveFromCameraValue_H

#include "../CommandBase.h"
#include "WPILib.h"

class MoveFromCameraValue: public CommandBase
{
public:
	MoveFromCameraValue();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

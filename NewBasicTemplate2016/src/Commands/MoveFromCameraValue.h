#ifndef MoveFromCameraValue_H
#define MoveFromCameraValue_H

#include "../CommandBase.h"
#include "WPILib.h"

class MoveFromCameraValue: public CommandBase
{
private:
	bool isgood = false;
	bool isgoodFirst = false;
	float motorSpeed =.6f;
	Timer* timer;
	int pos;
	int offset;
public:
	MoveFromCameraValue(int position);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

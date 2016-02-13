#ifndef RaiseAndLowerArm_H
#define RaiseAndLowerArm_H

#include "../CommandBase.h"
#include "WPILib.h"

class RaiseAndLowerArm: public CommandBase
{
private:
	double sliderValue;

	int direction;
public:
	RaiseAndLowerArm(bool);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

	static const bool UP = true;
	static const bool DOWN = false;
};

#endif

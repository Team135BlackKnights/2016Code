#ifndef AutonomousDrive_H
#define AutonomousDrive_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonomousDrive: public CommandBase
{
public:
	AutonomousDrive(float, float, int);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	Timer* timer;
	float left, right;
	int targetTime;
	const int DEFAULT_TIME = 10;
};

#endif

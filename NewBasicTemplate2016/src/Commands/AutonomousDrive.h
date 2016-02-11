#ifndef AutonomousDrive_H
#define AutonomousDrive_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonomousDrive: public CommandBase
{
public:
	AutonomousDrive(float x, float y, int time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	Timer* timer;
	float x, y;
	int targetTime;
	const int ALONGTIME = 99999999;
};

#endif

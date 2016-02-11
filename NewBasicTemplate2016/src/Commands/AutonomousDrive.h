#ifndef AutonomousDrive_H
#define AutonomousDrive_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonomousDrive: public CommandBase
{
public:
	AutonomousDrive(float x, float y);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	Timer* timer;
	float x, y;
};

#endif

#ifndef DriveShooter_H
#define DriveShooter_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveShooter: public CommandBase
{
public:
	DriveShooter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	float shootPower = 1.0f;
	std::unique_ptr<Timer> time;
};

#endif

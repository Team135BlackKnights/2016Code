#ifndef DriveFlashlight_H
#define DriveFlashlight_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveFlashlight: public CommandBase
{
private:
	bool switched;
	std::unique_ptr<Timer> timer;
public:
	DriveFlashlight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

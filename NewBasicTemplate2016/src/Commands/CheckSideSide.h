#ifndef TeleOpAimbot_H
#define TeleOpAimbot_H

#include "../CommandBase.h"
#include "WPILib.h"

class CheckSideSide: public CommandBase
{
public:
	CheckSideSide();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	bool isgood = false;
};

#endif

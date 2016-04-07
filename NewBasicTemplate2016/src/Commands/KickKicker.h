#ifndef KickKicker_H
#define KickKicker_H

#include "../CommandBase.h"
#include "WPILib.h"

class KickKicker: public CommandBase
{
public:
	KickKicker();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	std::unique_ptr<Timer> timer;
	bool done = false;
};

#endif

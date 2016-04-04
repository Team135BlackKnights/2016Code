#ifndef KickUnstucker_H
#define KickUnstucker_H

#include "../CommandBase.h"
#include "WPILib.h"

class KickUnstucker: public CommandBase
{
public:
	KickUnstucker();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

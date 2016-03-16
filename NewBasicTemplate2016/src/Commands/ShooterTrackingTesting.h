#ifndef ShooterTrackingTesting_H
#define ShooterTrackingTesting_H

#include "../CommandBase.h"
#include "WPILib.h"

class ShooterTrackingTesting: public CommandBase
{
public:
	ShooterTrackingTesting();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

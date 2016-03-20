#ifndef ShootBoulder_H
#define ShootBoulder_H

#include "../CommandBase.h"
#include "WPILib.h"

class ShootBoulder: public CommandBase
{
private:
	//  Still To Be Determined
	const int setEncoderVelocity = 100;

	int encoderVelocity;

	std::unique_ptr<Timer> timer;

	double timeWait;
	bool timerStarted;

	double initialTimerValue = 0.0D,
		   finalTimerValue = 0.0D;

	bool upToSpeed = false;
public:
	ShootBoulder();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

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
	bool speedSet;

	std::unique_ptr<Timer> timer;
	double initalTimerValue,
		   finalTimerValue;

	double timeWait = .2;

	int placer;
public:
	ShootBoulder();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

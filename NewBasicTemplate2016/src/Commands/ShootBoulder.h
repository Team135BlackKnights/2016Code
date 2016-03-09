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

	bool timerStarted = false;

	static constexpr double timeWait = .05D;
public:
	ShootBoulder();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

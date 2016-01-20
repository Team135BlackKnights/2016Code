#ifndef PIDTesting_H
#define PIDTesting_H

#include "../CommandBase.h"
#include "WPILib.h"

class PIDTesting: public CommandBase
{
private:
	int PortNumber = 2;
	//  std::unique_ptr<LiveWindow> lw;
	//  std::unique_ptr<CANTalon> talon;
	int PValue,
		IValue,
		DValue;

	int Power = .5;
	double encoderValue;

	std::unique_ptr<Timer> timer;

	double timerValue;

public:
	PIDTesting();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

#ifndef SerialCommunicationTesting_H
#define SerialCommunicationTesting_H

#include "../CommandBase.h"
#include "WPILib.h"

class SerialCommunicationTesting: public CommandBase
{
private:
	double shooterTrackerValue = 0.0D;

public:
	SerialCommunicationTesting();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

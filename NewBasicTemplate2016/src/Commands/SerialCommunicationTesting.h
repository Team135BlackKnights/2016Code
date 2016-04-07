#ifndef SerialCommunicationTesting_H
#define SerialCommunicationTesting_H

#include "../CommandBase.h"
#include "WPILib.h"

class SerialCommunicationTesting: public CommandBase
{
private:
	double shooterTrackerValue = 0.0D;
	float sonarDistanceValue = 0.0f;

public:
	SerialCommunicationTesting();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

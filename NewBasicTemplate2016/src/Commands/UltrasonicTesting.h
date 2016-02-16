#ifndef UltrasonicTesting_H
#define UltrasonicTesting_H

#include "../CommandBase.h"
#include "WPILib.h"

class UltrasonicTesting: public CommandBase
{
private:
	double leftSonarDistance,
		   rightSonarDistance,
		   lightSensorDistance;

	//  int i;
public:
	UltrasonicTesting();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

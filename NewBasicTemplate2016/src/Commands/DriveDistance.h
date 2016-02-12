#ifndef DriveDistance_H
#define DriveDistance_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveDistance: public CommandBase
{
private:
	double inchesDistance;
	double distanceFromLeftEncoder,
		   distanceFromRightEncoder;

	double motorPower = .6;
public:
	DriveDistance(double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

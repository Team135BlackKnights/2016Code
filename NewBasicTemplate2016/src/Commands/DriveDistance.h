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

	double leftMotorPower = .6,
		   rightMotorPower = .6;

	bool leftDone,
		 rightDone;
public:
	DriveDistance(double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

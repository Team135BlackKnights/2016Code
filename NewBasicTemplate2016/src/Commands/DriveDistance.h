#ifndef DriveDistance_H
#define DriveDistance_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveDistance: public CommandBase
{
private:
	double inchesDistance;
	//  The currentDistance the encoder values return
	double distanceFromLeftEncoder,
		   distanceFromRightEncoder;

	double leftMotorPower = .6D,
		   rightMotorPower = .6D;

	bool leftDone,
		 rightDone;

	int intialDistance,
		finalDistance;
public:
	DriveDistance(double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

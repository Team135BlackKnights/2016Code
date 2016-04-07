#ifndef CenterRobotAfterOverDefense_H
#define CenterRobotAfterOverDefense_H

#include "../CommandBase.h"
#include "WPILib.h"

class CenterRobotAfterOverDefense: public CommandBase
{
private:
	double angleDegrees;

	bool rightOrLeft;

	float motorPower = 0.0f;

	int leftEncoderPositionToTravel = 0,
	    leftInitialEncoderPosition = 0;

	int leftCurrentEncoderPosition = 0;

	bool turnAngleReached = false;
public:
	CenterRobotAfterOverDefense(float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

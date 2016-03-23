#ifndef TurnRobotAngle_H
#define TurnRobotAngle_H

#include "../CommandBase.h"
#include "WPILib.h"

class TurnRobotAngle: public CommandBase
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
	TurnRobotAngle(double, bool, float = .8f);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

	static const bool RIGHT_TURN = true,
					  LEFT_TURN = !RIGHT_TURN;
};

#endif

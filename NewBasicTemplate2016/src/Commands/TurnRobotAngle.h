#ifndef TurnRobotAngle_H
#define TurnRobotAngle_H

#include "../CommandBase.h"
#include "WPILib.h"

class TurnRobotAngle: public CommandBase
{
private:
	int angleDegrees;

	bool rightOrLeft;

	static constexpr float MOTOR_POWER = 0.625f;

	int rightEncoderPositionToTravel = 0,
	    rightInitialEncoderPosition = 0;

	int rightCurrentEncoderPosition = 0;

	bool turnAngleReached = false;
public:
	TurnRobotAngle(int, bool);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

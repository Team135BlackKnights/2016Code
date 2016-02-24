#ifndef TurnRobotAngle_H
#define TurnRobotAngle_H

#include "../CommandBase.h"
#include "WPILib.h"

class TurnRobotAngle: public CommandBase
{
private:
	int currentEncoderPosition;

	int initialEncoderValue,
		encoderPositionToTurn;

	int angleToTurn;
	int directionToSpin;

	static constexpr float motorPower = .5;

	bool rightOrLeft;
public:
	TurnRobotAngle(int, bool);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

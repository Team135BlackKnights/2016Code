#ifndef DriveBox_H
#define DriveBox_H

#include "../CommandBase.h"
#include "WPILib.h"

class Move: public CommandBase
{
private:
	float speedLeft;
	int speedRight;
public:
	Move(float);
	Move(float, float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

	static const int FORWARD = 1;
	static const int REVERSE = -1;
};

#endif

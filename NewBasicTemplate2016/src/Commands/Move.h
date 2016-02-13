#ifndef DriveBox_H
#define DriveBox_H

#include "../CommandBase.h"
#include "WPILib.h"

class Move: public CommandBase
{
private:
	int directionLeft;
	int directionRight;
public:
	Move(bool);
	Move(bool, bool);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

	static const bool FORWARD = true;
	static const bool REVERSE = false;
};

#endif

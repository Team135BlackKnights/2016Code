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
};

#endif

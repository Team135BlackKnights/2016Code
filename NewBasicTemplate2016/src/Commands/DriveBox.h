#ifndef DriveBox_H
#define DriveBox_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveBox: public CommandBase
{
private:
	const int motorSpeed = .5;

	int direction;
public:
	DriveBox(bool);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

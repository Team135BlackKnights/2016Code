#ifndef DriveDistance_H
#define DriveDistance_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveDistance: public CommandBase
{
private:
	int inchesDistance;

	bool zero;

	static const int DISTANCE_BETWEEN_AUTOLINE_AND_DEFENSE = 72;
	static const int DRIVE_DISTANCE_TO_RAMP = DISTANCE_BETWEEN_AUTOLINE_AND_DEFENSE - LENGTH_OF_ROBOT;
public:
	DriveDistance(int, bool = false);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

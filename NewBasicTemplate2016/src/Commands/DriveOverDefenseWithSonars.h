#ifndef DriveOverDefenseWithSonars_H
#define DriveOverDefenseWithSonars_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveOverDefenseWithSonars: public CommandBase
{
private:
	float motorPower;

	bool rightSonarOverDefense = false;
	bool leftSonarOverDefense = false;

	bool rightOrLeft;

	bool offCenterLeftTurn = false,
		 offCenterRightTurn = false;

	double initialDistance = 0,
		   finalDistance = 0;

	bool overDefense;
public:
	DriveOverDefenseWithSonars(float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

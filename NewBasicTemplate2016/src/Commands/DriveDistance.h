#ifndef DriveDistance_H
#define DriveDistance_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveDistance: public CommandBase
{
private:
	float rightInitialDistance = 0,
		  rightFinalDistance = 0,
		  rightCurrentDistance = 0;

	float leftInitialDistance = 0,
		  leftFinalDistance = 0,
		  leftCurrentDistance = 0;


	float leftMotorPower,
		  rightMotorPower;

	int inchesDistance;

	bool zero;

	bool leftDistanceReached = false,
		 rightDistanceReached = false;

	static const int DISTANCE_BETWEEN_AUTOLINE_AND_DEFENSE = 72;
	static const int DRIVE_DISTANCE_TO_RAMP = DISTANCE_BETWEEN_AUTOLINE_AND_DEFENSE - LENGTH_OF_ROBOT;
public:
	DriveDistance(int inchesDistance, float motorPower = .6f, bool zero = false);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

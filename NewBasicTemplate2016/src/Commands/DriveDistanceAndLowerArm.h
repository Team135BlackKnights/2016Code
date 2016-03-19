#ifndef DriveToDefenseAndLowerArm_H
#define DriveToDefenseAndLowerArm_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"
#include "RobotMap.h"

class DriveDistanceAndLowerArm: public CommandGroup
{
private:
	static const int DISTANCE_BETWEEN_AUTOLINE_AND_DEFENSE = 72;
	static const int DRIVE_DISTANCE_TO_RAMP = DISTANCE_BETWEEN_AUTOLINE_AND_DEFENSE - LENGTH_OF_ROBOT;

	static const bool ZERO = true;
public:
	DriveDistanceAndLowerArm(bool lowBar);
};

#endif

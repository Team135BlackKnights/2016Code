#ifndef DriveToDefenseAndLowerArm_H
#define DriveToDefenseAndLowerArm_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"
#include "RobotMap.h"

class DriveDistanceAndLowerArm: public CommandGroup
{
public:
	DriveDistanceAndLowerArm(int, bool, bool);
};

#endif

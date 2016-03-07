#ifndef AutoCommand_H
#define AutoCommand_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"
#include "DriveDistance.h"

class AutoCommand: public CommandGroup
{
private:
	static const int lowBarDistance,
				     rockWallDistance,
					 roughTerrainDistance,
					 moatDistance,
					 rampartsDistance;

	static const int DISTANCE_BETWEEN_AUTOLINE_AND_DEFENSE = 72;
	static const int DRIVE_DISTANCE_TO_RAMP = DISTANCE_BETWEEN_AUTOLINE_AND_DEFENSE - LENGTH_OF_ROBOT;
public:
	AutoCommand(DriveTrain::TYPE_OF_DEFENSE, int);
};

#endif

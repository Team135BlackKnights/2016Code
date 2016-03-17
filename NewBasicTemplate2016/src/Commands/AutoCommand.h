#ifndef AutoCommand_H
#define AutoCommand_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"
#include "RobotMap.h"

class AutoCommand: public CommandGroup
{
private:
	static const int lowBarDistance = 36 + LENGTH_OF_ROBOT,
				     rockWallDistance = 36 + LENGTH_OF_ROBOT,
					 roughTerrainDistance = 36 + LENGTH_OF_ROBOT,
					 moatDistance = 36 + LENGTH_OF_ROBOT,
					 rampartsDistance = 40 + LENGTH_OF_ROBOT;

	static const int distanceToTravelOverDefense = 40 + LENGTH_OF_ROBOT;

	static const bool RIGHT = true,
					  LEFT = false;

	static const bool ZERO = true;

	static constexpr float MOTOR_POWER_TO_RAMP = 0.8f;

	float motorSpeed;
public:
	AutoCommand(bool, int, bool);
};

#endif

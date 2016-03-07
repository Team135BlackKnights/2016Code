#ifndef AutoCommand_H
#define AutoCommand_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"
#include "DriveDistance.h"
#include "TurnRobotAngle.h"

class AutoCommand: public CommandGroup
{
private:
	static const int lowBarDistance = 80,
				     rockWallDistance = 80,
					 roughTerrainDistance = 80,
					 moatDistance = 80,
					 rampartsDistance = 80;

	static const int DISTANCE_BETWEEN_AUTOLINE_AND_DEFENSE = 72;
	static const int DRIVE_DISTANCE_TO_RAMP = DISTANCE_BETWEEN_AUTOLINE_AND_DEFENSE - LENGTH_OF_ROBOT;

	static const bool RIGHT = true,
					  LEFT = false;

	static const bool ZERO = true;

	static constexpr float MOTOR_POWER_TO_RAMP = 0.6f;
public:
	AutoCommand(DriveTrain::TYPE_OF_DEFENSE, int);
};

#endif

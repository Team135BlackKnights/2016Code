#ifndef GetRobotOverDefenseIntoPosition_H
#define GetRobotOverDefenseIntoPosition_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"
#include "RobotMap.h"
#include "../CommandBase.h"

class GetRobotOverDefenseIntoPosition: public CommandGroup
{
private:

	static const int DISTANCE_BETWEEN_AUTOLINE_AND_DEFENSE = 72;
	static constexpr float DISTANCE_NEED_TO_TRAVEL = DISTANCE_BETWEEN_AUTOLINE_AND_DEFENSE - LENGTH_OF_ROBOT;
public:
	GetRobotOverDefenseIntoPosition(AnalogSensors::DEFENSE_METHOD, int);
};

#endif

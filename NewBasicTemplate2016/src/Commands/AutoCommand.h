#ifndef AutoCommand_H
#define AutoCommand_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"
#include "RobotMap.h"

class AutoCommand: public CommandGroup
{
private:
	static const int DISTANCE_TO_TRAVEL_OVER_DEFENSE = 70 + LENGTH_OF_ROBOT;

	static const int DISTANCE_TO_TRAVEL_AFTER_CROSSING_DEFENSE = 20;

	static const bool ZERO_ENCODER = true;
	static const bool NON_ZERO_ENCODER = false;

	static constexpr float MOTOR_POWER_TO_RAMP = 0.8f;

	float motorSpeed;

	static const int DISTANCE_BETWEEN_AUTOLINE_AND_DEFENSE = 72;
	static const int DRIVE_DISTANCE_TO_RAMP = DISTANCE_BETWEEN_AUTOLINE_AND_DEFENSE - LENGTH_OF_ROBOT - 12;
public:
	AutoCommand(int, bool, bool);
};

#endif

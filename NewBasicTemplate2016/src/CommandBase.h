#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <Subsystems/AxisCam.h>
#include <string>
#include "Commands/Command.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/AxisCam.h"
#include "OI.h"
#include "WPILib.h"
#include <Subsystems/AxisCam.h>

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{
public:
	CommandBase(const std::string &name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static std::unique_ptr<DriveTrain> driveTrain;
	static std::unique_ptr<OI> oi;
	static std::unique_ptr<AxisCam> cam;
};

#endif

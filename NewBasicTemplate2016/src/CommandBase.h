#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include "WPILib.h"
#include "OI.h"
#include <string>
#include "Commands/Command.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/LogData.h"
#include "Subsystems/LiftHang.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/SerialCommunication.h"
#include "Subsystems/Arm.h"
/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{
public:
	//CommandBase(const std::string &name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static std::unique_ptr<DriveTrain> driveTrain;
	static std::unique_ptr<OI> oi;
	static std::unique_ptr<LogData> logData;
	static std::unique_ptr<Shooter> shooter;
	static std::unique_ptr<LiftHang> liftHang;
	static std::unique_ptr<SerialCommunication> serialCommunication;
	static std::unique_ptr<Arm> arm;
};

#endif

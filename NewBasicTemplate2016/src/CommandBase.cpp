#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
std::unique_ptr<DriveTrain> CommandBase::driveTrain;
std::unique_ptr<OI> CommandBase::oi;
//std::unique_ptr<LogData> CommandBase::logData;
//std::unique_ptr<Preferences> CommandBase::preferences;

/*
CommandBase::CommandBase(const std::string &name) :
		Command(name)
{
}
*/

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	driveTrain.reset(new DriveTrain());

	oi.reset(new OI());

	//logData.reset(new LogData());

	//preferences.reset(Preferences::GetInstance());
}

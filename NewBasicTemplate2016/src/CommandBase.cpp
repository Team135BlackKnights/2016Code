
#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
std::unique_ptr<DriveTrain> CommandBase::driveTrain;
std::unique_ptr<OI> CommandBase::oi;
std::unique_ptr<SerialCommunication> CommandBase::serialCommunication;

CommandBase::CommandBase(const std::string &name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	driveTrain.reset(new DriveTrain());
	oi.reset(new OI());
	serialCommunication.reset(new SerialCommunication());
}

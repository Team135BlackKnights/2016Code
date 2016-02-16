#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
std::unique_ptr<DriveTrain> CommandBase::driveTrain;
std::unique_ptr<OI> CommandBase::oi;
std::unique_ptr<Shooter> CommandBase::shooter;
std::unique_ptr<LogData> CommandBase::logData;
std::unique_ptr<LiftHang> CommandBase::liftHang;
std::unique_ptr<SerialCommunication> CommandBase::serialCommunication;

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

	shooter.reset(new Shooter());

	liftHang.reset(new LiftHang());

	logData.reset(new LogData("/home/lvuser/"));

	serialCommunication.reset(new SerialCommunication());

	//preferences.reset(Preferences::GetInstance());
}

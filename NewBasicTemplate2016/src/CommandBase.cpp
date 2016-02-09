
#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
std::unique_ptr<DriveTrain> CommandBase::driveTrain;
std::unique_ptr<OI> CommandBase::oi;
std::unique_ptr<LiftHang> CommandBase::liftHang;
std::unique_ptr<AxisCam> CommandBase::cam;

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
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	//driveTrain.reset(new DriveTrain());

	oi.reset(new OI());

	liftHang.reset(new LiftHang());

	cam.reset(new AxisCam());
}

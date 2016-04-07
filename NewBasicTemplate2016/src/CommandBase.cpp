#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
std::unique_ptr<OI> CommandBase::oi;
std::unique_ptr<Shooter> CommandBase::shooter;
std::unique_ptr<Arm> CommandBase::arm;
//std::unique_ptr<Preferences> CommandBase::preferences;

std::unique_ptr<DriveTrain> CommandBase::driveTrain;
std::unique_ptr<LiftHangWinch> CommandBase::liftHangWinch;
std::unique_ptr<LiftHangFlipFlip> CommandBase::liftHangFlip;
std::unique_ptr<AxisCam> CommandBase::cam;
std::unique_ptr<Flashlight> CommandBase::flashlight;
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
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.

	shooter.reset(new Shooter());

	arm.reset(new Arm());

	driveTrain.reset(new DriveTrain());

	oi.reset(new OI());

	liftHangWinch.reset(new LiftHangWinch());

	liftHangFlip.reset(new LiftHangFlipFlip());

	cam.reset(new AxisCam());

	flashlight.reset(new Flashlight());

	serialCommunication.reset(new SerialCommunication());
}

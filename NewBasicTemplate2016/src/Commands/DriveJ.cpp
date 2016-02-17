#include <Commands/DriveJ.h>
#include <OI.h>
#include <Subsystems/DriveTrain.h>
#include <cstdbool>
#include <memory>

DriveJ::DriveJ()
{
	Requires(driveTrain.get());
}


void DriveJ::Initialize() {
}


void DriveJ::Execute()
{
	driveTrain->DriveTank(oi->GetStick(OI::LEFT), oi->GetStick(OI::RIGHT));
}


bool DriveJ::IsFinished()
{
	return false;
}


void DriveJ::End() {}


void DriveJ::Interrupted() {}

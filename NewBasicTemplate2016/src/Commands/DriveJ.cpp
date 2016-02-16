#include <Commands/DriveJ.h>
#include "RobotMap.h"

DriveJ::DriveJ()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain.get());
}

// Called just before this Command runs the first time
void DriveJ::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void DriveJ::Execute()
{

	//driveTrain->DriveTank(oi->GetStickY(OI::LEFT), oi->GetStickY(OI::RIGHT)); //Drives the Robot depending on x-y-z speed values
	driveTrain->DriveTank(oi->GetStick(OI::LEFT), oi->GetStick(OI::RIGHT));
}

// Make this return true when this Command no longer needs to run execute()
bool DriveJ::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveJ::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveJ::Interrupted() {}

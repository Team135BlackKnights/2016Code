#include <Commands/DriveJ.h>
#include <OI.h>
#include <Subsystems/AxisCam.h>
#include <Subsystems/DriveTrain.h>
#include <cstdbool>
#include <memory>

DriveJ::DriveJ()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain.get());
}

// Called just before this Command runs the first time
void DriveJ::Initialize() {
	//this->inverted = Preferences::GetInstance()->GetBoolean("Inverted", false);
	//  Invert the motors on the driveTrain
	driveTrain->InvertMotors();
}

// Called repeatedly when this Command is scheduled to run
void DriveJ::Execute()
{
	//  Drives the Robot depending on y values from the left and right joysticks
	driveTrain->DriveTank(oi->GetStickY(OI::LEFT), oi->GetStickY(OI::RIGHT));
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

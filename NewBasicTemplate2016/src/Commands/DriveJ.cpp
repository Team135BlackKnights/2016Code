#include <Commands/DriveJ.h>
#include <OI.h>
#include <Subsystems/DriveTrain.h>
#include <Subsystems/USBCam.h>
#include <cstdbool>
#include <memory>

DriveJ::DriveJ()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	inverted = false;
	Requires(driveTrain.get());
	Requires(caMeRa.get());
}

// Called just before this Command runs the first time
void DriveJ::Initialize() {
	//this->inverted = SmartDashboard::GetBoolean("Inverted", false);
	driveTrain->Invert(this->inverted);
}

// Called repeatedly when this Command is scheduled to run
void DriveJ::Execute()
{
	//bool newInvert = SmartDashboard::GetBoolean("Inverted", this->inverted);
	//if (newInvert != this->inverted)
		//driveTrain->Invert(newInvert);

	driveTrain->DriveTank(oi->GetStickY(OI::LEFT), oi->GetStickY(OI::RIGHT)); //Drives the Robot depending on x-y-z speed values
	//testing, just sending x, y
	caMeRa->findBiggest();
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

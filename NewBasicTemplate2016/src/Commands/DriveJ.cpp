#include <Commands/DriveJ.h>
#include "RobotMap.h"
#include "../Subsystems/DriveTrain.h"

DriveJ::DriveJ()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	inverted = true;
	Requires(driveTrain.get());
}

// Called just before this Command runs the first time
void DriveJ::Initialize() {
	//this->inverted = Preferences::GetInstance()->GetBoolean("Inverted", false);
	driveTrain->SetupMotors();
	driveTrain->ZeroAllEncoders();
	driveTrain->InvertMotors(this->inverted);
}

// Called repeatedly when this Command is scheduled to run
void DriveJ::Execute()
{
	//bool newInvert = Preferences::GetInstance()->GetBoolean("Inverted", this->inverted);
	//if (newInvert != this->inverted)
	//{
		//this->inverted = newInvert;
		//driveTrain->InvertMotors(this->inverted);
	//}
	driveTrain->SetMotorValue(DriveTrain::FRONT_RIGHT, .1);
	driveTrain

	//  driveTrain->DriveTank(oi->GetStickY(OI::LEFT), oi->GetStickY(OI::RIGHT)); //Drives the Robot depending on x-y-z speed values
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

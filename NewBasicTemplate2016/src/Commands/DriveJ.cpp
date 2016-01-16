#include <Commands/DriveJ.h>
#include "RobotMap.h"
#include "../Subsystems/DriveTrain.h"

DriveJ::DriveJ()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	inverted = false;
	Requires(driveTrain.get());
}

// Called just before this Command runs the first time
void DriveJ::Initialize() {
	this->inverted = Preferences::GetInstance()->GetBoolean("Inverted", false);
	driveTrain->InvertMotors(this->inverted);
}

// Called repeatedly when this Command is scheduled to run
void DriveJ::Execute()
{
	bool newInvert = Preferences::GetInstance()->GetBoolean("Inverted", this->inverted);
	if (newInvert != this->inverted)
	{
		this->inverted = newInvert;
		driveTrain->InvertMotors(this->inverted);
	}


	driveTrain->DriveTank(oi->GetStickY(OI::LEFT), oi->GetStickY(OI::RIGHT)); //Drives the Robot depending on x-y-z speed values

	encoderValues[FRONT_LEFT] = driveTrain->GetEncoderValues(FRONT_LEFT);
	encoderValues[FRONT_RIGHT] = driveTrain->GetEncoderValues(FRONT_RIGHT);
	encoderValues[REAR_LEFT] = driveTrain->GetEncoderValues(REAR_LEFT);
	encoderValues[REAR_RIGHT] = driveTrain->GetEncoderValues(REAR_RIGHT);

	SmartDashboard::PutNumber(FrontLeftString, encoderValues[FRONT_LEFT]);
	SmartDashboard::PutNumber(FrontRightString, encoderValues[FRONT_RIGHT]);
	SmartDashboard::PutNumber(RearLeftString, encoderValues[REAR_LEFT]);
	SmartDashboard::PutNumber(RearRightString, encoderValues[REAR_RIGHT]);

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

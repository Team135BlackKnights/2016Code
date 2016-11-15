#include <Commands/DriveJ.h>
#include <OI.h>
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
	//driveTrain->SetupMotors();
	//driveTrain->ZeroAllEncoders();
	driveTrain->InvertMotors();
}

// Called repeatedly when this Command is scheduled to run
void DriveJ::Execute()
{
	//int inverted = oi->driver->DRIVE_TRAIN_INVERTED ? -1 : 1;
	float drivePower = Preferences::GetInstance()->GetFloat("DrivePower", 1.0f);
	//driveTrain->DriveTank(oi->GetStickY(OI::LEFT), oi->GetStickY(OI::RIGHT)); //Drives the Robot depending on x-y-z speed values
	driveTrain->DriveTank(oi->GetStickY(OI::LEFT) * drivePower, oi->GetStickY(OI::RIGHT) * drivePower);
	std::cout << "Driven: " << driveTrain->GetDistanceInches(DriveTrain::FRONT_LEFT) << std::endl;
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

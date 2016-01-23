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
	/*for (int i = 0; i < NUM_OF_MOTORS; i++) {
		//  This will zero out all the encoders before the code below executes
		driveTrain->ZeroEncoder(i);
	}*/
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

	/*
	driveTrain->DriveTank(oi->GetStickY(OI::LEFT), oi->GetStickY(OI::RIGHT)); //Drives the Robot depending on x-y-z speed values


	SmartDashboard::PutNumber(FrontLeftString, driveTrain->GetRevsPerSecond(FRONT_LEFT));
	SmartDashboard::PutNumber(FrontRightString, driveTrain->GetRevsPerSecond(FRONT_RIGHT));
	SmartDashboard::PutNumber(RearLeftString, driveTrain->GetRevsPerSecond(REAR_LEFT));
	SmartDashboard::PutNumber(RearRightString, driveTrain->GetRevsPerSecond(REAR_RIGHT));
	*/


	//  Plan: Try to figure out Count of Encoder, or at least the value the encoder displays on SmartDashboard
	//  This will tell me if there is a X4 or Quadrature Effect on the count of the Encoder
	//  Step 1: Set up encoder so I can turn the "Pole" easily
	//  Step 2: Turn encoder "Pole" a half rotation, record value, full rotation, record value
	//  Motor Port still TBD
	SmartDashboard::PutNumber("Encoder Position is: ", driveTrain->GetEncoderPosition(FRONT_LEFT));
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

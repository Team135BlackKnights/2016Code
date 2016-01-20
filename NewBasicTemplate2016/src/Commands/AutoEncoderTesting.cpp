#include "AutoEncoderTesting.h"
#include "Subsystems/DriveTrain.h"

AutoEncoderTesting::AutoEncoderTesting()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain.get());
	inverted = false;
	timer.reset(new Timer());
}

// Called just before this Command runs the first time
void AutoEncoderTesting::Initialize()
{
	this->inverted = Preferences::GetInstance()->GetBoolean("Inverted", false);
	driveTrain->InvertMotors(this->inverted);
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutoEncoderTesting::Execute()
{
	driveTrain->DriveTank(motorTestSpeed, motorTestSpeed);

	SmartDashboard::PutNumber(FrontLeftString, driveTrain->GetVelocity(FRONT_LEFT));
	SmartDashboard::PutNumber(FrontRightString, driveTrain->GetVelocity(FRONT_RIGHT));
	SmartDashboard::PutNumber(RearLeftString, driveTrain->GetVelocity(REAR_LEFT));
	SmartDashboard::PutNumber(RearRightString, driveTrain->GetVelocity(REAR_RIGHT));

}

// Make this return true when this Command no longer needs to run execute()
bool AutoEncoderTesting::IsFinished()
{
	if (timer->Get() >= timeLimit) {
		return true;
	}
	else {
		return false;
	}
}

// Called once after isFinished returns true
void AutoEncoderTesting::End()
{
	SmartDashboard::PutNumber(FrontLeftString, driveTrain->GetVelocity(FRONT_LEFT));
	SmartDashboard::PutNumber(FrontRightString, driveTrain->GetVelocity(FRONT_RIGHT));
	SmartDashboard::PutNumber(RearLeftString, driveTrain->GetVelocity(REAR_LEFT));
	SmartDashboard::PutNumber(RearRightString, driveTrain->GetVelocity(REAR_RIGHT));
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoEncoderTesting::Interrupted()
{

}

#include "ShooterTrackingTesting.h"

ShooterTrackingTesting::ShooterTrackingTesting()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(shooter.get());
}

// Called just before this Command runs the first time
void ShooterTrackingTesting::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ShooterTrackingTesting::Execute()
{
	std::cout << "ShooterTrackerValue: " << shooter->GetShooterTrackerValue() << std::endl;
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterTrackingTesting::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ShooterTrackingTesting::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterTrackingTesting::Interrupted()
{

}

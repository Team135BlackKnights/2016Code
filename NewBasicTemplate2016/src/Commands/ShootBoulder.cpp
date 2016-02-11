#include "ShootBoulder.h"

ShootBoulder::ShootBoulder()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(shooter.get());
	speedSet = false;
	encoderVelocity = 0;
}

// Called just before this Command runs the first time
void ShootBoulder::Initialize()
{
	shooter->ZeroAllEncoders();
}

// Called repeatedly when this Command is scheduled to run
void ShootBoulder::Execute()
{
	encoderVelocity = shooter->GetEncoderVelocity(Shooter::TWO_WHEEL_SHOOTER_MOTOR);

	shooter->ShootBoulder();

	if (encoderVelocity >= setEncoderVelocity) {
		speedSet = true;
		SmartDashboard::PutBoolean("Shooter Up to Speed: ", speedSet);
	}
	else {
		speedSet = false;
		SmartDashboard::PutBoolean("Shooter Up to Speed: ", speedSet);
	}

}

// Make this return true when this Command no longer needs to run execute()
bool ShootBoulder::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ShootBoulder::End()
{
	speedSet = false;
	shooter->StopShootBoulder();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShootBoulder::Interrupted()
{
	End();
}

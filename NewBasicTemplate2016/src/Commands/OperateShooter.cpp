#include "OperateShooter.h"

OperateShooter::OperateShooter(bool PosOrNeg)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(shooter.get());
	//  collectionMotorPower = .6;
	twoWheelShooterPower = .8;
	positiveOrNegative = PosOrNeg ? 1:-1;

}

// Called just before this Command runs the first time
void OperateShooter::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void OperateShooter::Execute()
{

	shooter->DriveMotor(Shooter::TWO_WHEEL_SHOOTER_MOTOR, twoWheelShooterPower * positiveOrNegative);
}

// Make this return true when this Command no longer needs to run execute()
bool OperateShooter::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void OperateShooter::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OperateShooter::Interrupted()
{

}

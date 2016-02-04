#include "OperateShooter.h"

OperateShooter::OperateShooter()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(shooter.get());
	collectionMotorPower = .6;
	twoWheelShooterPower = 1.0;
}

// Called just before this Command runs the first time
void OperateShooter::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void OperateShooter::Execute()
{
	joystickYValue = oi->GetStickY(OI::MANIPULATOR_JOYSTICK);
	shooter->DriveMotor(Shooter::RAISE_OR_LOWER_ARM, joystickYValue);

	shooter->DriveMotor(Shooter::COLLECTION_MOTOR, collectionMotorPower);

	shooter->DriveMotor(Shooter::TWO_WHEEL_SHOOTER_MOTOR, twoWheelShooterPower);
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

#include "ShooterCommand.h"

ShooterCommand::ShooterCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(shooter.get());
	timer.reset(new Timer());
	timerValue = 0;
	encoderVelocity = 0;
}

// Called just before this Command runs the first time
void ShooterCommand::Initialize()
{
	shooter->ZeroAllEncoders();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void ShooterCommand::Execute()
{
	encoderVelocity = shooter->GetEncoderVelocity(MOTOR_SHOOTER_RIGHT);
	timerValue = timer->Get();

	SmartDashboard::PutNumber("Time: ", timerValue);
	SmartDashboard::PutNumber("Encoder Velocoty: ", encoderVelocity);

	shooter->LogOneEncoderValue(MOTOR_SHOOTER_RIGHT, timerValue, encoderVelocity);

}

// Make this return true when this Command no longer needs to run execute()
bool ShooterCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ShooterCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterCommand::Interrupted()
{

}

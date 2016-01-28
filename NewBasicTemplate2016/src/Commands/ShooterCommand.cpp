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
	shooter->SetPIDValues();
	shooter->UpdateMotorToReflectCurrentPIDValues(motorPort, "Shooter-PValue", "Shooter-IValue", "Shooter-DValue");
	shooter->BasedSubsytemCreateFileNameWithPID("Shooter", "EncoderVelocity", PValue, IValue, DValue);
}

// Called repeatedly when this Command is scheduled to run
void ShooterCommand::Execute()
{
	//  encoderVelocity = shooter->GetEncoderVelocity(Shooter::MOTOR_SHOOTER_RIGHT);
	timerValue = timer->Get();

	SmartDashboard::PutNumber("Time: ", timerValue);
	//  SmartDashboard::PutNumber("Encoder Velocoty: ", encoderVelocity);

	shooter->LogEncoderData(motorPort, timerValue, VELOCITY_LOG);

}

// Make this return true when this Command no longer needs to run execute()
bool ShooterCommand::IsFinished()
{
	return timer->HasPeriodPassed(TIME);
}

// Called once after isFinished returns true
void ShooterCommand::End()
{
	shooter->CloseFile();
	timer->Stop();
	timer->Reset();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterCommand::Interrupted()
{
	this->End();
}

#include "PIDTesting.h"

PIDTesting::PIDTesting()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain.get());
	timer.reset(new Timer());

	SmartDashboard::GetNumber("PValue", PValue);
	SmartDashboard::GetNumber("IValue", IValue);
	SmartDashboard::GetNumber("DValue", DValue);
}

// Called just before this Command runs the first time
void PIDTesting::Initialize()
{
	driveTrain->SetPIDValues(PortNumber, PValue, IValue, DValue);
	driveTrain->ZeroEncoder(PortNumber);
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void PIDTesting::Execute()
{
	driveTrain->SetMotorValue(PortNumber, Power);
	encoderValue = driveTrain->GetEncoderVelocity(PortNumber);
	timerValue = timer->Get();
	SmartDashboard::PutNumber("Encoder Velocity", encoderValue);
	SmartDashboard::PutNumber("Timer", timerValue);

	//  How to Graph these values??
}

// Make this return true when this Command no longer needs to run execute()
bool PIDTesting::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void PIDTesting::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PIDTesting::Interrupted()
{

}

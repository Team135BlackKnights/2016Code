#include "PIDTesting.h"
#include "Subsystems/LogData.h"

PIDTesting::PIDTesting()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain.get());
	timer.reset(new Timer());

	this->PValue = SmartDashboard::GetNumber("PValue", PValue);
	this->IValue = SmartDashboard::GetNumber("IValue", IValue);
	this->DValue = SmartDashboard::GetNumber("DValue", DValue);
}

// Called just before this Command runs the first time
void PIDTesting::Initialize()
{
	driveTrain->SetPIDValues(motorPort, this->PValue, this->IValue, this->DValue);
	driveTrain->ZeroEncoder(motorPort);
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void PIDTesting::Execute()
{
	driveTrain->SetMotorValue(motorPort, Power);
	encoderValue = driveTrain->GetEncoderVelocity(motorPort);
	timerValue = timer->Get();
	SmartDashboard::PutNumber("Encoder Velocity", encoderValue);
	SmartDashboard::PutNumber("Timer", timerValue);

	logData->WriteData(timerValue, encoderValue, PIDFileName);
}

// Make this return true when this Command no longer needs to run execute()
bool PIDTesting::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void PIDTesting::End()
{
	logData->CloseFile();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PIDTesting::Interrupted()
{
	logData->WriteData(000, 000, PIDFileName);
	logData->CloseFile();
}

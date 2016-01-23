#include "PIDTesting.h"

PIDTesting::PIDTesting()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain.get());
	timer.reset(new Timer());
	timerValue = 0;

	//PValue = SmartDashboard::GetNumber("PValue", PValue);
	//SmartDashboard::GetNumber("IValue", IValue);
	//SmartDashboard::GetNumber("DValue", DValue);
}

// Called just before this Command runs the first time
void PIDTesting::Initialize()
{
	//driveTrain->SetPIDValues(PortNumber, PValue, IValue, DValue);
	driveTrain->ZeroAllEncoders();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void PIDTesting::Execute()
{
	int index = 0;
	std::cout << "Executing?" << std::endl;
	//encoderValue = driveTrain->GetEncoderVelocity(PortNumber);
	timerValue = timer->Get();
	//SmartDashboard::PutNumber("Encoder Velocity", encoderValue);
	SmartDashboard::PutNumber("Timer", timerValue);


	driveTrain->LogEncoderData(index, timerValue);

	//  How to Graph these values??
}

// Make this return true when this Command no longer needs to run execute()
bool PIDTesting::IsFinished()
{
	if (timer->Get() >= 15) {
		return true;
	}
	else {
		return false;
	}
}

// Called once after isFinished returns true
void PIDTesting::End()
{
	driveTrain->CloseFile();
	std::cout << "Ended" << std::endl;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PIDTesting::Interrupted()
{
	std::cout << "Interrupted" << std::endl;
	driveTrain->CloseFile();
}

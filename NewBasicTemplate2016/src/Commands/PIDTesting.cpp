#include "PIDTesting.h"
#include <sstream>

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

	//  Creates a File Name Based off of the Current Time
	driveTrain->BasedTimeCreateFileName();

	//  In the Data Logging File that will be created, the first two lines will write the P, I, and D Values Set
	driveTrain->SetPIDValues(p, i, d, MotorPort);
	driveTrain->DisplayPIDValuesInLogData(p, i, d);
}

// Called repeatedly when this Command is scheduled to run
void PIDTesting::Execute()
{
	int index = 0;
	//std::cout << "Executing?" << std::endl;
	//encoderValue = driveTrain->GetEncoderVelocity(PortNumber);
	timerValue = timer->Get();
	//SmartDashboard::PutNumber("Encoder Velocity", encoderValue);
	SmartDashboard::PutNumber((std::string)"Timer", timerValue);
	SmartDashboard::PutNumber((std::string)"Timer", timerValue);
	encoderEncPosition = driveTrain->GetEncoderPosition(MotorPort);
	encoderPosition = driveTrain->GetPosition(MotorPort);


	driveTrain->LogTwoEncoderValues(index, timerValue, encoderEncPosition, encoderPosition);

	//  How to Graph these values??
}

// Make this return true when this Command no longer needs to run execute()
bool PIDTesting::IsFinished()
{
	if (timer->Get() >= 5) {
		return true;
	}
	else {
		return false;
	}
}

// Called once after isFinished returns true
void PIDTesting::End()
{
	driveTrain->ClosePIDFile();
	timer->Stop();
	timer->Reset();
	std::cout << "Ended" << std::endl;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PIDTesting::Interrupted()
{
	std::cout << "Interrupted" << std::endl;
	driveTrain->ClosePIDFile();
	timer->Stop();
	timer->Reset();
}

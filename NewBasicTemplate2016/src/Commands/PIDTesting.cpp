#include "PIDTesting.h"
#include <sstream>
#include "Subsystems/PIDLogging.h"



//  Using this now to test the difference between GetPosition(), GetEncPosition()
PIDTesting::PIDTesting()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(shooter.get());
	  timer.reset(new Timer());
	  timerValue = 0;

	//  PIDLogging::driveTrainBool = true;
	//PValue = SmartDashboard::GetNumber("PValue", PValue);
	//SmartDashboard::GetNumber("IValue", IValue);
	//SmartDashboard::GetNumber("DValue", DValue);
}

// Called just before this Command runs the first time
void PIDTesting::Initialize()
{
	//driveTrain->SetPIDValues(PortNumber, PValue, IValue, DValue);
	//  driveTrain->SetPIDPreferences();
	shooter->ZeroAllEncoders();
	timer->Start();

	shooter->SetupMotors();

	//  Creates a File Name Based off of the Current Time
	shooter->ChangeFileNameWithSubsystemName();
	//  driveTrain->BasedTimeCreateFileName();
	shooter->OpenFile();
	shooter->DisplayPIDValuesInLogData();
	shooter->LogEncoderDataHeader(this->VELOCITY_LOG);

	//  In the Data Logging File that will be created, the first two lines will write the P, I, and D Values Set
	shooter->SetPIDPreferences();
}

// Called repeatedly when this Command is scheduled to run
void PIDTesting::Execute()
{
	//  driveTrain->EnableMotorControl(motorIndex);
	shooter->DriveShooterMotors(motorPower);
	//  int index = 0;
	//std::cout << "Executing?" << std::endl;
	timerValue = timer->Get();
	encoderValue = shooter->GetEncoderVelocity(motorIndex);
	//  SmartDashboard::PutNumber("Encoder Velocity", encoderEncPosition);
	//  SmartDashboard::PutNumber((std::string)"Timer", timerValue);
	//  std::cout << driveTrain->GetMotorExpiration(motorIndex);
	//std::cout << timerValue;

	// encoderEncPosition = driveTrain->GetEncoderPosition(motorIndex);
	// encoderSpeed = driveTrain->GetEncoderVelocity(motorIndex);
	//driveTrain->LogTwoEncoderValues(motorIndex, timerValue, encoderEncPosition, encoderSpeed);
	shooter->LogEncoderData(motorIndex, timerValue, PIDLogging::VELOCITY);


	//  driveTrain->LogTwoEncoderValues(index, timerValue, encoderEncPosition, encoderPosition);

	//  How to Graph these values??
}

// Make this return true when this Command no longer needs to run execute()
bool PIDTesting::IsFinished()
{
	if (timerValue <= 5) {
		return true;
	}
	else {
		return false;
	}
}

// Called once after isFinished returns true
void PIDTesting::End()
{
	//driveTrain->ClosePIDFile();
	timer->Stop();
	timer->Reset();
	std::cout << "Ended" << std::endl;
	shooter->StopShooterMotors();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PIDTesting::Interrupted()
{
	std::cout << "Interrupted" << std::endl;
	shooter->StopShooterMotors();
	//driveTrain->ClosePIDFile();
	timer->Stop();
	timer->Reset();
}

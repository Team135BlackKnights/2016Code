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

	  initalTimerValue = 0;
	  finalTimerValue = 0;

	  encoderVelocity = 0;
	  speedSet = false;

	  placer = 0;


	//  PIDLogging::driveTrainBool = true;
	//PValue = SmartDashboard::GetNumber("PValue", PValue);
	//SmartDashboard::GetNumber("IValue", IValue);
	//SmartDashboard::GetNumber("DValue", DValue);
}

// Called just before this Command runs the first time
void PIDTesting::Initialize()
{
	//driveTrain->SetPIDValues(PortNumber, PValue, IValue, DValue);
	//shooter->SetPIDPreferences();
	shooter->ZeroEncoder(Shooter::TWO_WHEEL_SHOOTER_MOTOR);
	//timer->Reset();
	//timer->Start();

	//  Creates a File Name Based off of the Current Time
	//shooter->ChangeFileNameWithSubsystemName();
	//  driveTrain->BasedTimeCreateFileName();
	//shooter->OpenFile();
	//shooter->DisplayPIDValuesInLogData();
	//shooter->LogEncoderDataHeader(this->VELOCITY_LOG);

	//  In the Data Logging File that will be created, the first two lines will write the P, I, and D Values Set
	//shooter->SetPIDPreferences();
}

// Called repeatedly when this Command is scheduled to run
void PIDTesting::Execute()
{
	//  driveTrain->EnableMotorControl(motorIndex);
	shooter->DriveShooterMotors();
	//  int index = 0;
	//std::cout << "Executing?" << std::endl;
	//timerValue = timer->Get();
	encoderVelocity = shooter->GetEncoderVelocity(Shooter::TWO_WHEEL_SHOOTER_MOTOR);

	//shooter->LogEncoderData(Shooter::TWO_WHEEL_SHOOTER_MOTOR, timerValue, PIDLogging::VELOCITY);

	/*if (encoderVelocity >= setEncoderVelocity) {
			placer = placer + 1;
			speedSet = true;
			//SmartDashboard::PutBoolean("Shooter Up to Speed: ", speedSet);

			if (placer == 1) {
				initalTimerValue = timer->Get();
				finalTimerValue = initalTimerValue + timeWait;
			}
			if (finalTimerValue >= timer->Get()) {
				shooter->DriveKicker(Shooter::KICKER_KICKED);
			}
		}
		else {
			placer = 0;
			speedSet = false;
			//SmartDashboard::PutBoolean("Shooter Up to Speed: ", speedSet);
		} */
	//  SmartDashboard::PutNumber("Encoder Velocity", encoderEncPosition);
	//  SmartDashboard::PutNumber((std::string)"Timer", timerValue);
	//  std::cout << driveTrain->GetMotorExpiration(motorIndex);
	//std::cout << timerValue;

	// encoderEncPosition = driveTrain->GetEncoderPosition(motorIndex);
	// encoderSpeed = driveTrain->GetEncoderVelocity(motorIndex);
	//driveTrain->LogTwoEncoderValues(motorIndex, timerValue, encoderEncPosition, encoderSpeed);


	//  driveTrain->LogTwoEncoderValues(index, timerValue, encoderEncPosition, encoderPosition);

	//  How to Graph these values??
}

// Make this return true when this Command no longer needs to run execute()
bool PIDTesting::IsFinished()
{
	/*if (timerValue >= 5) {
		return true;
	}
	else {
		return false;
	} */
	return false;
}

// Called once after isFinished returns true
void PIDTesting::End()
{
	//driveTrain->ClosePIDFile();
	//timer->Stop();
	//timer->Reset();
	//speedSet = false;
	//std::cout << "Ended" << std::endl;
	shooter->StopShooterMotors();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PIDTesting::Interrupted()
{
	//std::cout << "Interrupted" << std::endl;
	shooter->StopShooterMotors();
	//driveTrain->ClosePIDFile();
	//timer->Stop();
	//timer->Reset();
	//speedSet = false;
}

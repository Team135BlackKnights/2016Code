#include "TestingMotors.h"

TestingMotors::TestingMotors()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(motorTesting.get());
	preferences.reset(new Preferences());
	talonMotorID = 0;
	victorMotorID = 0;

	this->invertTalon = false;
	this->invertVictor = false;
}

// Called just before this Command runs the first time
void TestingMotors::Initialize()
{
	this->invertTalon = preferences->GetBoolean("Invert Talon", false);
	this->invertVictor = preferences->GetBoolean("Invert Victor", false);

	talonMotorID = preferences->GetInt("Talon Motor ID", 0);
	victorMotorID = preferences->GetInt("Victor Motor ID", 0);

	motorTesting->InvertTalonMotor(talonMotorID, this->invertTalon);
	motorTesting->InvertVictorMotor(victorMotorID, this->invertVictor);

}

// Called repeatedly when this Command is scheduled to run
void TestingMotors::Execute()
{
	motorTesting->RunTalonMotor(talonMotorID);
	motorTesting->RunVictorMotor(victorMotorID);
}

// Make this return true when this Command no longer needs to run execute()
bool TestingMotors::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void TestingMotors::End()
{
	motorTesting->StopTalonMotor(talonMotorID);
	motorTesting->StopVictorMotor(victorMotorID);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TestingMotors::Interrupted()
{
	End();
}

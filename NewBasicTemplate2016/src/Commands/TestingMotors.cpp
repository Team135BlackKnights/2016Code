#include "TestingMotors.h"
#include "OI.h"

TestingMotors::TestingMotors(bool PosNeg)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(motorTesting.get());
	talonMotorID = 0;
	victorMotorID = 0;

	this->invertTalon = false;
	this->invertVictor = false;

	motorPower = 0;

	direction = PosNeg ? 1: -1;

	//victorMotor.reset(new VictorSP(1));

	//victorMotor = new VictorSP(2);
}

// Called just before this Command runs the first time
void TestingMotors::Initialize()
{
	//this->invertTalon = Preferences::GetInstance()->GetBoolean("Invert Talon", false);
	//this->invertVictor = Preferences::GetInstance()->GetBoolean("Invert Victor", false);

	talonMotorID = Preferences::GetInstance()->GetInt("Talon Motor ID", 0);
	victorMotorID = Preferences::GetInstance()->GetInt("Victor Motor ID", 0);

	//motorTesting->InvertTalonMotor(talonMotorID, this->invertTalon);
	//motorTesting->InvertVictorMotor(victorMotorID, this->invertVictor);

}

// Called repeatedly when this Command is scheduled to run
void TestingMotors::Execute()
{
	motorPower = oi->GetStickSlider(OI::LEFT);

	motorTesting->RunTalonMotor(talonMotorID, motorPower * direction);
	motorTesting->RunVictorMotor(victorMotorID, motorPower * direction);
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

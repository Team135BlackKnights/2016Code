#include "MotorTesting.h"
#include "../RobotMap.h"

MotorTesting::MotorTesting() :
		Subsystem("MotorTesting")
{

}

void MotorTesting::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void MotorTesting::RunTalonMotor(int motorID) {
	cantalonMotor.reset(new CANTalon(motorID));
	cantalonMotor->Set(this->motorPower);
}

void MotorTesting::InvertTalonMotor(int motorID, bool inverted) {
	cantalonMotor.reset(new CANTalon(motorID));
	cantalonMotor->SetInverted(inverted);
}

void MotorTesting::StopTalonMotor(int motorID) {
	cantalonMotor.reset(new CANTalon(motorID));
	cantalonMotor->Set(0.0);
}

void MotorTesting::RunVictorMotor(int motorID) {
	victorMotor.reset(new VictorSP(motorID));
	victorMotor->Set(this->motorPower);
}

void MotorTesting::InvertVictorMotor(int motorID, bool inverted) {
	victorMotor.reset(new VictorSP(motorID));
	victorMotor->SetInverted(inverted);
}

void MotorTesting::StopVictorMotor(int motorID) {
	victorMotor.reset(new VictorSP(motorID));
	victorMotor->Set(0.0);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

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

void MotorTesting::RunTalonMotor(int motorID, float motorPower) {
	cantalonMotor.reset(new CANTalon(motorID));
	cantalonMotor->Set(motorPower);
}

void MotorTesting::RunVictorMotor(int motorID, float motorPower) {
	victorMotor.reset(new VictorSP(motorID));
	victorMotor->Set(motorPower);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

#include "Shooter.h"
#include "../RobotMap.h"

Shooter::Shooter() :
	PIDLogging("Shooter", "/home/lvuser/", 1.0, 0.0, 0.0, NUM_MOTORS, RADIUS)
{

}

void Shooter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Shooter::SetMotorValue(int motorPort, double motorPower) {

	//  Do I need to change the control mode to set the motor speed if the motors are currently in kPosition mode?
	//  motors[motorPort]->SetControlMode(CANTalon::kPercentVbus);

	//  Set() is determined upon what mode the CANTalon is in
	motors[motorPort]->Set(motorPower);
}

#include "Shooter.h"
#include "../RobotMap.h"

Shooter::Shooter() :
	PIDLogging("Shooter", "/home/lvuser/",NUM_MOTORS, RADIUS)
{

	//  The motor ID's still need to be configured
	motors[MOTOR_SHOOTER_RIGHT] = new CANTalon(MOTOR_SHOOTER_RIGHT_ID);
	motors[MOTOR_SHOOTER_LEFT] = new CANTalon(MOTOR_SHOOTER_LEFT_ID);
	this->SetupMotors();
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

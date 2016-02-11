#include "Shooter.h"
#include "../RobotMap.h"

Shooter::Shooter() :
	PIDLogging("Shooter", "/home/lvuser/", numMotors, radius)
{

	//  shooter.reset(new CANTalon(MOTOR_SHOOT_BOULDER));
	//  motors[TWO_WHEEL_SHOOTER_MOTOR] = shooter.get();
	motors[TWO_WHEEL_SHOOTER_MOTOR] = new CANTalon(MOTOR_SHOOT_BOULDER);
}

void Shooter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Shooter::DriveShooterMotors() {
	motors[TWO_WHEEL_SHOOTER_MOTOR]->Set(shooterMotorPower);
}

void Shooter::StopShooterMotors() {
	motors[TWO_WHEEL_SHOOTER_MOTOR]->Set(0);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

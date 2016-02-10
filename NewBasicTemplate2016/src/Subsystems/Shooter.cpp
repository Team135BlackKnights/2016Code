#include "Shooter.h"
#include "../RobotMap.h"

Shooter::Shooter() :
	PIDLogging("Shooter", "/home/lvuser/", numMotors, radius)
{

	//  shooter.reset(new CANTalon(MOTOR_SHOOT_BOULDER));
	//  motors[TWO_WHEEL_SHOOTER_MOTOR] = shooter.get();
	motors[TWO_WHEEL_SHOOTER_MOTOR] = new CANTalon(MOTOR_SHOOT_BOULDER);
	motors[RAISE_LOWER_ARM] = new CANTalon(MOTOR_RAISE_LOWER_ARM);

}

void Shooter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Shooter::ShootBoulder() {
	motors[TWO_WHEEL_SHOOTER_MOTOR]->Set(shooterMotorPower);
}

void Shooter::RaiseLowerArm(double motorPower) {
	motors[RAISE_LOWER_ARM]->Set(motorPower);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

#include "Shooter.h"
#include "../RobotMap.h"

Shooter::Shooter() :
	PIDLogging("DriveTrain", "/home/lvuser/", numMotors, radius)
{

	shooter.reset(new CANTalon(MOTOR_SHOOT_BOULDER));
	motors[TWO_WHEEL_SHOOTER_MOTOR] = shooter.get();

}

void Shooter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Shooter::DriveMotor(int motorIndex, double motorPower) {
	motors[motorIndex]->Set(motorPower);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

#include "Shooter.h"
#include "../RobotMap.h"

Shooter::Shooter() :
	PIDLogging("Shooter", "/home/lvuser/", numMotors, radius)
{

	shooter.reset(new CANTalon(MOTOR_SHOOT_BOULDER));
	//  motors[TWO_WHEEL_SHOOTER_MOTOR] = shooter.get();
	motors[TWO_WHEEL_SHOOTER_MOTOR] = shooter.get();

	motors[TWO_WHEEL_SHOOTER_MOTOR]->SetFeedbackDevice(CANTalon::FeedbackDevice::CtreMagEncoder_Relative);
	motors[TWO_WHEEL_SHOOTER_MOTOR]->SetStatusFrameRateMs(CANTalon::StatusFrameRate::StatusFrameRateQuadEncoder, 15);
	//  Magnetic Encoder Count is either 256, 1024 quadrature;  OR 1024, 4096 quadrature


	kicker.reset(new Servo(Servo_SHOOTER_KICKER));
}

void Shooter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Shooter::DriveShooterMotors(float power) {
	motors[TWO_WHEEL_SHOOTER_MOTOR]->Set(power);
}

void Shooter::StopShooterMotors() {
	motors[TWO_WHEEL_SHOOTER_MOTOR]->Set(0);
}

void Shooter::DriveKicker(float power) {
	kicker->Set(power);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

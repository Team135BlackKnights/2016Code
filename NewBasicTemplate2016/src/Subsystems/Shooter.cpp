#include "Shooter.h"
#include "../RobotMap.h"
#include "../Commands/DriveShooter.h"

Shooter::Shooter() :
	PIDLogging("Shooter", "/home/lvuser/", numMotors, radius)
{

	shooter.reset(new CANTalon(MOTOR_SHOOT_BOULDER));
	//  motors[TWO_WHEEL_SHOOTER_MOTOR] = shooter.get();
	motors[TWO_WHEEL_SHOOTER_MOTOR] = shooter.get();
	kicker.reset(new Servo(SERVO_SHOOTER_KICKER));
}

void Shooter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveShooter());
}

void Shooter::DriveShooterMotors(float power) {
	bool value = (GetEncoderSpeed() >= 21000.0D);
	double speed = GetEncoderSpeed();
	SmartDashboard::PutNumber((std::string)"Shooter Speed", speed);
	SmartDashboard::PutBoolean((std::string)"Shooter Up to Speed", value);
	motors[TWO_WHEEL_SHOOTER_MOTOR]->Set(power);
}

void Shooter::StopShooterMotors() {
	motors[TWO_WHEEL_SHOOTER_MOTOR]->Set(0);
}

void Shooter::DriveKicker(float value) {
	//Kicker shouldn't fight itself now!
	if (this->kicker->Get() != value)
		kicker->Set(value);
}

double Shooter::GetEncoderSpeed()
{
	return motors[TWO_WHEEL_SHOOTER_MOTOR]->GetSpeed();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

#include "Shooter.h"
#include "../RobotMap.h"
#include "../Commands/DriveShooter.h"
#include "../Commands/ShooterTrackingTesting.h"

Shooter::Shooter() :
	PIDLogging("Shooter", "/home/lvuser/", numMotors, radius)
{

	shooter.reset(new CANTalon(MOTOR_SHOOT_BOULDER));
	//  motors[TWO_WHEEL_SHOOTER_MOTOR] = shooter.get();
	motors[TWO_WHEEL_SHOOTER_MOTOR] = shooter.get();
	//kicker.reset(new Servo(SERVO_SHOOTER_KICKER));
	kicker.reset(new Solenoid(SOLENOID_SHOOTER_KICKER));

	//motors[TWO_WHEEL_SHOOTER_MOTOR]->SetFeedbackDevice(CANTalon::FeedbackDevice::AnalogPot);
	//motors[TWO_WHEEL_SHOOTER_MOTOR]->SetStatusFrameRateMs(CANTalon::StatusFrameRate::StatusFrameRateQuadEncoder, 15);
	DriveKicker(KICKER_RESET);

	shooterTracker.reset(new Counter(DIGITAL_SHOOTER_TRACKER));
}

void Shooter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new DriveShooter());
	SetDefaultCommand(new ShooterTrackingTesting());
}

void Shooter::DriveShooterMotors(float power) {
	double speed = GetEncoderSpeed();
	bool value = (speed >= 21000.0D);
	SmartDashboard::PutNumber((std::string)"Shooter Speed", speed);
	SmartDashboard::PutBoolean((std::string)"Shooter Up to Speed", value);
	motors[TWO_WHEEL_SHOOTER_MOTOR]->Set(power);
}

void Shooter::StopShooterMotors() {
	shooter->Set(0);
}

void Shooter::DriveKicker(bool value) {
	//Kicker shouldn't fight itself now!
	if (this->kicker->Get() != value)
		kicker->Set(value);
}

double Shooter::GetEncoderSpeed()
{
	return shooter->GetEncVel();
}

bool Shooter::ShooterUpToSpeed() {
	double encoderVelocity = GetEncoderSpeed();
	return encoderVelocity > MAG_ENCODER_SETPOINT;
}

bool Shooter::GetDigitalShooterTrackerValue() {
	//return shooterTracker->Get();
	return false;
}

double Shooter::GetShooterTrackerPeriod() {
	double time = shooterTracker->GetPeriod();
	return ConnerConversion(time);
}

double Shooter::ConnerConversion(double value) {
	return (double) Trunc(135.000000f * (1.0f/value), 3);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

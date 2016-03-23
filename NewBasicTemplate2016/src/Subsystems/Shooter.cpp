#include "Shooter.h"
#include "../RobotMap.h"
#include "../Commands/DriveShooter.h"

Shooter::Shooter() :
	PIDLogging("Shooter", "/home/lvuser/", numMotors, radius)
{

	shooter.reset(new CANTalon(MOTOR_SHOOT_BOULDER));

	motors[TWO_WHEEL_SHOOTER_MOTOR] = shooter.get();
	motors[TWO_WHEEL_SHOOTER_MOTOR]->SetInverted(SHOOTER_INVERTED);

	kicker.reset(new Solenoid(SOLENOID_SHOOTER_KICKER));
	unstucker.reset(new Solenoid(SOLENOID_SHOOTER_UNSTUCKER));

	DriveKicker(KICKER_RESET);

	shooterTracker.reset(new Counter(DIGITAL_SHOOTER_TRACKER));
}

void Shooter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveShooter());
}

void Shooter::DriveShooterMotors(float power) {
	double speed = GetShooterTrackerPeriod();
	SmartDashboard::PutNumber((std::string)"Shooter Speed Conners", speed);
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

void Shooter::DriveUnstucker(bool value) {
	if (this->unstucker->Get() != value)
		unstucker->Set(value);
}

double Shooter::GetShooterTrackerPeriod() {
	double timeBetweenSpindles = shooterTracker->GetPeriod();
	tempConnerValue = ConnerConversion(timeBetweenSpindles);
	if (tempConnerValue <= 30000)
		currentConnerValue = tempConnerValue;

	return currentConnerValue;
}

double Shooter::ConnerConversion(double value) {
	return (double) Trunc((1.0f/value), 3);
}

bool Shooter::ShooterUpToSpeed() {
	double shooterTrackerValue = GetShooterTrackerPeriod();
	return shooterTrackerValue >= SHOOTER_TRACKER_SETPOINT;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

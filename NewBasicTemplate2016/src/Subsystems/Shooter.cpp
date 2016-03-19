#include "Shooter.h"
#include "../RobotMap.h"
#include "../Commands/DriveShooter.h"
//#include "../Commands/ShooterTrackingTesting.h"

Shooter::Shooter() :
	PIDLogging("Shooter", "/home/lvuser/", numMotors, radius)
{

	shooter.reset(new CANTalon(MOTOR_SHOOT_BOULDER));
	//  motors[TWO_WHEEL_SHOOTER_MOTOR] = shooter.get();
	motors[TWO_WHEEL_SHOOTER_MOTOR] = shooter.get();
	motors[TWO_WHEEL_SHOOTER_MOTOR]->SetInverted(SHOOTER_INVERTED);
	//kicker.reset(new Servo(SERVO_SHOOTER_KICKER));
	kicker.reset(new Solenoid(SOLENOID_SHOOTER_KICKER));

	DriveKicker(KICKER_RESET);

	shooterTracker.reset(new Counter(DIGITAL_SHOOTER_TRACKER));
}

void Shooter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveShooter());
	//SetDefaultCommand(new ShooterTrackingTesting());
}

void Shooter::DriveShooterMotors(float power) {
	double speed = GetShooterTrackerPeriod();
	bool shooterUpToSpeed = ShooterUpToSpeed();
	SmartDashboard::PutNumber((std::string)"Shooter Speed Conners", speed);
	SmartDashboard::PutNumber("Shooter Up To Speed: ", shooterUpToSpeed);
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

double Shooter::GetShooterTrackerPeriod() {
	double timeBetweenSpindles = shooterTracker->GetPeriod();
	double tempValue = ConnerConversion(timeBetweenSpindles);
	if (tempValue <= 30000)
		currentConnerValue = tempValue;

	return currentConnerValue;

	/*
	if (0 < currentConnerValue <= 500) {
		previousConnerValue = currentConnerValue;
		return currentConnerValue;
		timerStarted = false;
	}
	else if (currentConnerValue > 500 || currentConnerValue == 0) {
		if (!timerStarted) {
			initialTimeValue = time;
			finalTimeValue = initialTimeValue + 2.0D;
			timerStarted = true;
			return previousConnerValue;
		}
		else if (timerStarted) {
			return previousConnerValue;
		}
		else if (finalTimeValue == time && timerStarted) {
			return 0.0D;
		}
	}
	*/
}

double Shooter::ConnerConversion(double value) {
	return (double) Trunc((1.0f/value), 3);
}

bool Shooter::ShooterUpToSpeed() {
	double shooterTrackerValue = GetShooterTrackerPeriod();
	if (shooterTrackerValue >= SHOOTER_TRACKER_SETPOINT) {
		return true;
	}
	else {
		return false;
	}
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

#include "Shooter.h"
#include "../RobotMap.h"
#include "../Commands/DriveShooter.h"

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

double Shooter::GetShooterTrackerPeriod() {
	double timeBetweenSpindles = shooterTracker->GetPeriod();
	double tempValue = ConnerConversion(timeBetweenSpindles);
	if (tempValue <= 30000)
		currentConnerValue = tempValue;

	return currentConnerValue;
}

double Shooter::ConnerConversion(double value) {
	return (double) Trunc((1.0f/value), 3);
}

//  If sidesOfCastle == true, display true when the shooter wheels are moving at a faster rate
//  If sidesOfCastle == false, the robot should be shooting from the middle of the field, at a slightly slower rate
bool Shooter::ShooterUpToSpeed(bool sidesOfCastle) {
	double shooterTrackerValue = GetShooterTrackerPeriod();

	if (sidesOfCastle) {
		if (shooterTrackerValue >= SHOOTER_TRACKER_SETPOINT_SIDES) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (shooterTrackerValue >= SHOOTER_TRACKER_SETPOINT_MIDDLE) {
			return true;
		}
		else {
			return false;
		}
	}
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

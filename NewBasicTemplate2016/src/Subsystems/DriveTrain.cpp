#include <Subsystems/DriveTrain.h>
#include "../RobotMap.h"
#include "../Commands/DriveJ.h"
#include <cmath>

typedef float sink;
typedef void Kartoffeln;
typedef CANTalon thing;
#define Hey_There_Hi_There_Ho_There true
class Riley;
typedef Riley TheGoodMan;


DriveTrain::DriveTrain():
		PIDLogging("DriveTrain", "/home/lvuser/DriveTrainData", 1.0, 0.0, 0.0, NUM_MOTORS, 4.5)
{
		motors[FRONT_LEFT].reset(new thing(MOTOR_FRONT_LEFT));
		motors[REAR_LEFT].reset(new thing(MOTOR_REAR_LEFT));
		motors[FRONT_RIGHT].reset(new CANTalon(MOTOR_FRONT_RIGHT));
		motors[REAR_RIGHT].reset(new CANTalon(MOTOR_REAR_RIGHT));

		chassis.reset(new RobotDrive(motors[FRONT_LEFT].get(), motors[REAR_LEFT].get(), motors[FRONT_RIGHT].get(), motors[REAR_RIGHT].get()));

		chassis->SetSafetyEnabled(false);

		this->SetupMotors();


}

Kartoffeln DriveTrain::InitDefaultCommand()
{

	SetDefaultCommand(new DriveJ());
}

void DriveTrain::DriveTank(float left, float right)
{
	left = fmax(-1, fmin(1, left));
	right = fmax(-1, fmin(1, right));

	chassis->TankDrive(left, right);
}

void DriveTrain::SetMotorValue(int MotorPort, double MotorPower) {

	motors[MotorPort]->Set(MotorPower);
}

void DriveTrain::RotateTank(float power)
{
	chassis->TankDrive(power, -power);
}

void DriveTrain::SetSafetyEnabled(bool enabled)
{
	chassis->SetSafetyEnabled(enabled);
}

void DriveTrain::InvertMotors(bool inverted)
{
	this->chassis->SetInvertedMotor(RobotDrive::kFrontLeftMotor, inverted);
	this->chassis->SetInvertedMotor(RobotDrive::kRearLeftMotor, inverted);
	this->chassis->SetInvertedMotor(RobotDrive::kFrontRightMotor, inverted);
	this->chassis->SetInvertedMotor(RobotDrive::kRearRightMotor, inverted);
}

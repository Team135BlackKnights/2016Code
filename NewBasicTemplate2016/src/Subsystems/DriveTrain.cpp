#include <Subsystems/DriveTrain.h>
#include "../RobotMap.h"
#include "../Commands/DriveJ.h"
#include <cmath>

DriveTrain::DriveTrain():
	Subsystem("DriveTrain")
{

	motors[FRONT_LEFT].reset(new CANTalon(MOTOR_FRONT_LEFT));
	motors[REAR_LEFT].reset(new CANTalon(MOTOR_REAR_LEFT));
	motors[FRONT_RIGHT].reset(new CANTalon(MOTOR_FRONT_RIGHT));
	motors[REAR_RIGHT].reset(new CANTalon(MOTOR_REAR_RIGHT));

	chassis.reset(new RobotDrive(motors[FRONT_LEFT].get(), motors[REAR_LEFT].get(), motors[FRONT_RIGHT].get(), motors[REAR_RIGHT].get()));
	this->InvertMotors();

	chassis->SetSafetyEnabled(false);
}

void DriveTrain::InitDefaultCommand()
{

	//  SetDefaultCommand(new DriveJ());
}

void DriveTrain::DriveTank(Joystick* left, Joystick* right) {
	chassis->TankDrive(left, right);
}

void DriveTrain::DriveTank(float left, float right)
{
	//Eventually hope to drive with speed control, not power control
	left = fmax(-1, fmin(1, left));
	right = fmax(-1, fmin(1, right));

	chassis->TankDrive(left, right);
}

void DriveTrain::RotateTank(float power)
{
	chassis->TankDrive(power, -power);
}

void DriveTrain::SetSafetyEnabled(bool enabled)
{
	chassis->SetSafetyEnabled(enabled);
}

void DriveTrain::InvertMotors()
{
	this->chassis->SetInvertedMotor(RobotDrive::kFrontLeftMotor, DRIVE_TRAIN_INVERTED);
	this->chassis->SetInvertedMotor(RobotDrive::kRearLeftMotor, DRIVE_TRAIN_INVERTED);
	this->chassis->SetInvertedMotor(RobotDrive::kFrontRightMotor, DRIVE_TRAIN_INVERTED);
	this->chassis->SetInvertedMotor(RobotDrive::kRearRightMotor, DRIVE_TRAIN_INVERTED);
}

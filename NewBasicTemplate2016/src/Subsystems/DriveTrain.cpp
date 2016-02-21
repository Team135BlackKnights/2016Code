#include "DriveTrain.h"
#include "../RobotMap.h"
#include "Commands/DriveJ.h"
#include <cmath>
#include "PIDLogging.h"

typedef float sink;
typedef void Kartoffeln;
typedef CANTalon thing;
#define Hey_There_Hi_There_Ho_There true
class Riley;
typedef Riley TheGoodMan;


DriveTrain::DriveTrain():
		//PIDLogging("DriveTrain", "/home/lvuser/", NUM_MOTORS, RADIUS)
		Subsystem("DriveTrain")
{
		motors[FRONT_LEFT] = new CANTalon(MOTOR_FRONT_LEFT);
		motors[REAR_LEFT] = new CANTalon(MOTOR_REAR_LEFT);
		motors[FRONT_RIGHT] = new CANTalon(MOTOR_FRONT_RIGHT);
		motors[REAR_RIGHT] = new CANTalon(MOTOR_REAR_RIGHT);

		chassis.reset(new RobotDrive(motors[FRONT_LEFT], motors[REAR_LEFT], motors[FRONT_RIGHT], motors[REAR_RIGHT]));

		// chassis->SetExpiration(0.5);

		this->InvertMotors();

		chassis->SetSafetyEnabled(false);

		//this->SetupMotors();
		this->SetNeutralMode(BRAKE);


}

DriveTrain::~DriveTrain() {};

Kartoffeln DriveTrain::InitDefaultCommand()
{
	SetDefaultCommand(new DriveJ());
}

void DriveTrain::DriveTank(Joystick* left, Joystick* right) {
	chassis->TankDrive(left, right);
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

void DriveTrain::SetAllMotorValues(double motorPower) {
	motors[FRONT_LEFT]->Set(motorPower);
	motors[REAR_LEFT]->Set(motorPower);
	motors[FRONT_RIGHT]->Set(motorPower);
	motors[REAR_RIGHT]->Set(motorPower);

}

void DriveTrain::RotateTank(float power)
{
	chassis->TankDrive(power, -power);
}

void DriveTrain::SetSafetyEnabled(bool enabled)
{
	chassis->SetSafetyEnabled(enabled);
}

void DriveTrain::ClosePIDFile() {
	//this->CloseFile();
}


void DriveTrain::InvertMotors()
{
	this->chassis->SetInvertedMotor(RobotDrive::kFrontLeftMotor, DRIVE_TRAIN_INVERTED);
	this->chassis->SetInvertedMotor(RobotDrive::kRearLeftMotor, DRIVE_TRAIN_INVERTED);
	this->chassis->SetInvertedMotor(RobotDrive::kFrontRightMotor, DRIVE_TRAIN_INVERTED);
	this->chassis->SetInvertedMotor(RobotDrive::kRearRightMotor, DRIVE_TRAIN_INVERTED);
}

void DriveTrain::SetNeutralMode(bool coast)
{
	CANTalon::NeutralMode mode = (coast == COAST) ? CANTalon::NeutralMode::kNeutralMode_Coast : CANTalon::NeutralMode::kNeutralMode_Brake;
	for (int i = 0; i < NUM_MOTORS; i++) {
		motors[i]->ConfigNeutralMode(mode);
	}
}

void DriveTrain::ZeroEncoder(int motorIndex) {
	motors[motorIndex]->SetPosition(0);
}

int DriveTrain::GetEncoderPosition(int motorIndex) {
	return motors[motorIndex]->GetEncPosition();
}

double DriveTrain::GetDistanceInches(int motorIndex) {

	int encoderPosition = GetEncoderPosition(motorIndex);
	double REVS = (encoderPosition/QUADRATURE_COUNT);
	double DISTANCE_TRAVELED = REVS * CIRCUMFERENCE_OF_WHEEL;
	return DISTANCE_TRAVELED;
}

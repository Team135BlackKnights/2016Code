#include "DriveTrain.h"
#include "Commands/DriveJ.h"
#include <cmath>

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

		chassis->SetSafetyEnabled(false);

		//this->SetupMotors();
		this->SetNeutralMode(BRAKE);

		rightOrLeft = false;
		angleToTurnDegrees = 0.0D;
}

DriveTrain::~DriveTrain() {};

Kartoffeln DriveTrain::InitDefaultCommand()
{

	SetDefaultCommand(new DriveJ());
}

double DriveTrain::GetMotorExpiration(int motorIndex) {
	return motors[motorIndex]->GetExpiration();
}

void DriveTrain::EnableMotorControl(int motorIndex) {
	motors[motorIndex]->EnableControl();
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

void DriveTrain::SetNeutralMode(bool mode)
{
	std::cout << "CHANGING NETURAL MODE\t" << mode << std::endl;
	CANTalon::NeutralMode neutralMode = (mode == COAST) ? CANTalon::NeutralMode::kNeutralMode_Coast : CANTalon::NeutralMode::kNeutralMode_Brake;
	for (int i = 0; i < NUM_MOTORS; i++) {
		motors[i]->ConfigNeutralMode(neutralMode);
	}
}

float DriveTrain::GetDistanceInches(int motorIndex) {
	int encoderPosition = GetEncoderPosition(motorIndex);
	float numberOfRotations = encoderPosition / QUADRATURE_COUNT;
	float distanceTravelInches = numberOfRotations * GEAR_RATIO * CIRCUMFERENCE_OF_WHEELS;
	return distanceTravelInches;
}

int DriveTrain::GetEncoderPosition(int motorIndex) {
	return abs(motors[motorIndex]->GetEncPosition());
}

void DriveTrain::ZeroEncoder(int motorIndex)
{
	motors[motorIndex]->SetEncPosition(0);
}

int DriveTrain::GetEncoderPositionToTurnAngle(int angleDegrees) {
	float distanceToTravel = ((CIRCUMFERENCE_OF_TURNING_ROBOT * angleDegrees)/(360.0f));
	float numberOfRotationsOfWheels = distanceToTravel/CIRCUMFERENCE_OF_WHEELS;
	int encoderPosition = (numberOfRotationsOfWheels * ((float)QUADRATURE_COUNT));
	return (encoderPosition * (1/GEAR_RATIO));

}

void DriveTrain::CalculateAngleToTurnAfterCrossingDefense(double initialDistance, double finalDistance, bool rightOrLeft) {
	double differenceOfDistances = (finalDistance - initialDistance);
	if (differenceOfDistances >= 3.0D) {
		double angleToTurnRadians = atan(differenceOfDistances/((double)WIDTH_OF_ROBOT));
		this->angleToTurnDegrees = angleToTurnRadians * (180.0D/((double)M_PI));
	}
	else {
		this->angleToTurnDegrees = 0.0D;
	}

	this->rightOrLeft = rightOrLeft;
}

bool DriveTrain::GetDirectionToTurnAuto() {
	return this->rightOrLeft;
}

double DriveTrain::GetAngleToTurnAuto() {
	return this->angleToTurnDegrees;
}

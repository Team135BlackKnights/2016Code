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
	Subsystem("DriveTrain")
{
		motors[FRONT_LEFT].reset(new thing(MOTOR_FRONT_LEFT));
		motors[REAR_LEFT].reset(new thing(MOTOR_REAR_LEFT));
		motors[FRONT_RIGHT].reset(new CANTalon(MOTOR_FRONT_RIGHT));
		motors[REAR_RIGHT].reset(new CANTalon(MOTOR_REAR_RIGHT));

		chassis.reset(new RobotDrive(motors[FRONT_LEFT].get(), motors[REAR_LEFT].get(), motors[FRONT_RIGHT].get(), motors[REAR_RIGHT].get()));

		chassis->SetSafetyEnabled(false);

		for (int i = 0; i < NUM_MOTORS; i++) {
			motors[i]->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
			//  motors[i]->SetControlMode(CANTalon::kPosition);
			//  motors[i]->SetPosition(0);
			//  motors[i]->SetEncPosition(0);
			motors[i]->ConfigEncoderCodesPerRev(64);
		}

		quadratureCOUNT = COUNT * 4;

		CIRCUM = (2 * RADIUS) * 3.141593;

}

Kartoffeln DriveTrain::InitDefaultCommand()
{

	SetDefaultCommand(new DriveJ());
}

int DriveTrain::GetEncoderPosition(int MotorPort) {

	//  This value is equal to the (Count*4) * (Number of Revolutions of the Motor)
	return motors[MotorPort]->GetPosition();
}

int DriveTrain::GetEncoderVelocity(int MotorPort) {

	//  Gets the Speed Value (Encoder Ticks/.1sec.) of the Encoder
	//  The value will be Count*4 because it is a quadrature encoder
	return motors[MotorPort]->GetSpeed();
}

void DriveTrain::ZeroEncoder(int MotorPort) {

	//  Resets the Encoder Value to Zero
	motors[MotorPort]->SetPosition(0);
}

double DriveTrain::GetDistance(int MotorPort) {

	int encoderPosition = GetEncoderPosition(MotorPort);
	double REVS = (encoderPosition/quadratureCOUNT);
	double DISTANCE_TRAVELED = REVS * CIRCUM;
	return DISTANCE_TRAVELED;
}

double DriveTrain::GetVelocity(int MotorPort) {

	int encoderVelocity = GetEncoderVelocity(MotorPort);
	double NUM_REVS_PER_SEC = (encoderVelocity * 10)/(quadratureCOUNT);
	double DISTANCE_PER_SEC = NUM_REVS_PER_SEC * CIRCUM;
	return DISTANCE_PER_SEC;  //  Units: Inches per second

}

double DriveTrain::ReturnPIDInput(int MotorPort) {
	//  Get() the value from the sensor, in this case, encoder
	return GetVelocity(MotorPort);
}

void DriveTrain::FeedbackPIDOutput(double output) {
	//  PIDWrite()

}

void DriveTrain::DriveTank(float left, float right)
{
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

void DriveTrain::InvertMotors(bool inverted)
{
	this->chassis->SetInvertedMotor(RobotDrive::kFrontLeftMotor, inverted);
	this->chassis->SetInvertedMotor(RobotDrive::kRearLeftMotor, inverted);
	this->chassis->SetInvertedMotor(RobotDrive::kFrontRightMotor, inverted);
	this->chassis->SetInvertedMotor(RobotDrive::kRearRightMotor, inverted);
}

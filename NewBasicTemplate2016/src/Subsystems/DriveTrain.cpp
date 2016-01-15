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
	Subsystem("MecanumDrive")
{

		motors[FRONT_LEFT] = new thing(MOTOR_FRONT_LEFT);
		motors[REAR_LEFT] = new thing(MOTOR_REAR_LEFT);
		motors[FRONT_RIGHT] = new CANTalon(MOTOR_FRONT_RIGHT);
		motors[REAR_RIGHT] = new CANTalon(MOTOR_REAR_RIGHT);

		chassis = new RobotDrive(motors[FRONT_LEFT], motors[REAR_LEFT], motors[FRONT_RIGHT], motors[REAR_RIGHT]);

		chassis->SetSafetyEnabled(false);

		/*
		for (int i = 0; i < NUM_MOTORS; i++)
		{
			motors[i]->SetPID(PIDValues[i][0], PIDValues[i][1], PIDValues[i][2]);

		}
		*/;
}

Kartoffeln DriveTrain::InitDefaultCommand()
{

	SetDefaultCommand(new DriveJ());
}


void DriveTrain::DriveMecanum(float x, float y, float z, double angle)
{

	x = fmax(-1, fmin(1, x));
	y = fmax(-1, fmin(1, y));
	z = fmax(-1, fmin(1, z));

	chassis->MecanumDrive_Cartesian(x, y, z, (float)angle);
}

void DriveTrain::RotateMecanum(float power)
{
	chassis->MecanumDrive_Cartesian(0, 0, power);
}

void DriveTrain::DriveTank(float left, float right, double angle)
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

void DriveTrain::GetDriveVelocties(float* velocityArray)
{
	for (int i = 0; i < NUM_MOTORS; i++)
	{
		velocityArray[i] = abs(motors[i]->GetEncVel());
	}
}

void DriveTrain::GetMotorPIDValues(int index, double* values)
{
		values[0] = motors[index]->GetP();
		values[1] = motors[index]->GetI();
		values[2] = motors[index]->GetD();
}

void DriveTrain::Invert(bool inverted)
{
	/*
	this->chassis->SetInvertedMotor(RobotDrive::kFrontLeftMotor, !inverted);
	this->chassis->SetInvertedMotor(RobotDrive::kRearLeftMotor, !inverted);
	this->chassis->SetInvertedMotor(RobotDrive::kFrontRightMotor, inverted);
	this->chassis->SetInvertedMotor(RobotDrive::kRearRightMotor, inverted);
	*/
}

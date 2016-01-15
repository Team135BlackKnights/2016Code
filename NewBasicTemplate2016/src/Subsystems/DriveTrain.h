#ifndef MecanumDrive_H

#define MecanumDrive_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../OI.h"
#include <fstream>

class DriveTrain: public Subsystem
{
public:
	static const int NUM_MOTORS = 4;
private:
	CANTalon* motors[NUM_MOTORS];

	RobotDrive* chassis;


	double PIDValues[4][3] = {
			{0, 0, 0},
			{0, 0, 0},
			{0, 0, 0},
			{0, 0, 0}
	};

public:

	static const int 	FRONT_LEFT = RobotDrive::kFrontLeftMotor,
						REAR_LEFT = RobotDrive::kRearLeftMotor,
						FRONT_RIGHT = RobotDrive::kFrontRightMotor,
						REAR_RIGHT = RobotDrive::kRearRightMotor;

	DriveTrain();
	void InitDefaultCommand();

	void DriveMecanum(float, float, float, double=0);;
	void RotateMecanum(float);

	void DriveTank(float, float, double=0);
	void RotateTank(float);

	void SetSafetyEnabled(bool);

	void GetDriveVelocties(float*);

	void GetMotorPIDValues(int, double*);

	void Invert(bool inverted);
};

#endif

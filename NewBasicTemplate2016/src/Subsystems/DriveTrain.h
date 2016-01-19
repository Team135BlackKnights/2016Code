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
	std::unique_ptr<CANTalon> motors[NUM_MOTORS];

	std::unique_ptr<RobotDrive> chassis;


public:

	static const int 	FRONT_LEFT = RobotDrive::kFrontLeftMotor,
						REAR_LEFT = RobotDrive::kRearLeftMotor,
						FRONT_RIGHT = RobotDrive::kFrontRightMotor,
						REAR_RIGHT = RobotDrive::kRearRightMotor;

	DriveTrain();
	void InitDefaultCommand();

	void DriveTank(float, float);
	void RotateTank(float);

	void SetSafetyEnabled(bool);

	void InvertMotors(bool inverted);

	int GetEncoderPosition(int);
	int GetEncoderVelocity(int);
	void ZeroEncoder(int);

};

#endif

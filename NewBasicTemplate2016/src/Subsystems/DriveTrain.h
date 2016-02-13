#ifndef MecanumDrive_H
#define MecanumDrive_H

#include "PIDLogging.h"
#include "WPILib.h"
#include "../OI.h"
#include <fstream>
//#include "Commands/PIDTesting.h"

class DriveTrain: public PIDLogging
{
public:
	static const int NUM_MOTORS = 4;
private:
	//std::unique_ptr<CANTalon> motors[NUM_MOTORS];

	std::unique_ptr<RobotDrive> chassis;

	//  Need a value for the count of the encoder
	static const int COUNT = 64;

	//  Measured in Inches
	static const int RADIUS = 6;

public:

	static const int 	FRONT_LEFT = RobotDrive::kFrontLeftMotor,
						REAR_LEFT = RobotDrive::kRearLeftMotor,
						FRONT_RIGHT = RobotDrive::kFrontRightMotor,
						REAR_RIGHT = RobotDrive::kRearRightMotor;

	DriveTrain();
	~DriveTrain();
	void InitDefaultCommand();

	void DriveTank(float, float);
	void RotateTank(float);
	void SetMotorValue(int, double);
	void SetAllMotorValues(double);

	void SetSafetyEnabled(bool);

	void InvertMotors();
	void ClosePIDFile();

};

#endif

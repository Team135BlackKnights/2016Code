#ifndef MecanumDrive_H
#define MecanumDrive_H

#include "WPILib.h"
#include "../OI.h"
#include <fstream>
#include "Commands/Subsystem.h"
#include "RobotMap.h"

class DriveTrain: public Subsystem//public PIDLogging
{
public:
	static const int NUM_MOTORS = 4;
private:
	//std::unique_ptr<CANTalon> motors[NUM_MOTORS];

	CANTalon* motors[4];

	std::unique_ptr<RobotDrive> chassis;

	//  Need a value for the count of the encoder
	static const int COUNT = 64;
	static const int QUADRATURE_COUNT = COUNT * 4;

	static constexpr float GEAR_RATIO = 26.0f/60.0f;

	//  Measured in Inches
	static constexpr float RADIUS_OF_WHEELS = 6.0f;
	static constexpr float DIAMETER_OF_WHEELS = 2.0f * RADIUS_OF_WHEELS;
	static constexpr float CIRCUMFERENCE_OF_WHEELS = DIAMETER_OF_WHEELS * M_PI;

	static const int DISTANCE_BETWEEN_EDGE_AND_WHEEL = 2;
	static constexpr float CIRCUMFERENCE_OF_TURNING_ROBOT = ((WIDTH_OF_ROBOT - (2 * DISTANCE_BETWEEN_EDGE_AND_WHEEL)) * M_PI);

public:

	static const int 	FRONT_LEFT = RobotDrive::kFrontLeftMotor,
						REAR_LEFT = RobotDrive::kRearLeftMotor,
						FRONT_RIGHT = RobotDrive::kFrontRightMotor,
						REAR_RIGHT = RobotDrive::kRearRightMotor;

	static const bool COAST = true;
	static const bool BRAKE = false;

	DriveTrain();
	~DriveTrain();
	void InitDefaultCommand();

	void DriveTank(float, float);
	void RotateTank(float);
	void SetMotorValue(int, double);

	void SetSafetyEnabled(bool);

	void InvertMotors();
	void ClosePIDFile();

	double GetMotorExpiration(int);
	void EnableMotorControl(int);

	void SetNeutralMode(bool coast);

	int GetEncoderPosition(int);
	void ZeroEncoder(int);
	float GetDistanceInches(int);

	int GetEncoderPositionToTurnAngle(int);

};

#endif

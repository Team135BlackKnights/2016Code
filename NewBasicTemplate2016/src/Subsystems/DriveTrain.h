#ifndef MecanumDrive_H
#define MecanumDrive_H

#include "WPILib.h"
#include "../OI.h"
#include <fstream>
#include "Commands/Subsystem.h"

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
	static const int RADIUS_OF_WHEELS = 6;
	static const int DIAMETER_OF_WHEELS = 2 * RADIUS_OF_WHEELS;
	static const int CIRCUMFERENCE_OF_WHEELS = DIAMETER_OF_WHEELS * M_PI;

public:

	static const int 	FRONT_LEFT = RobotDrive::kFrontLeftMotor,
						REAR_LEFT = RobotDrive::kRearLeftMotor,
						FRONT_RIGHT = RobotDrive::kFrontRightMotor,
						REAR_RIGHT = RobotDrive::kRearRightMotor;

	static const bool COAST = true;
	static const bool BRAKE = false;

	enum TYPE_OF_DEFENSE {
		LOW_BAR,
		ROCK_WALL,
		ROUGH_TERRAIN,
		MOAT,
		RAMPARTS
	};

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

};

#endif

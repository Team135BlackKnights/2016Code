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
	static const int QUADRATURE_COUNT = 256;

	//  Measured in Inches
	static const int RADIUS = 6;
	static const int DIAMETER = 2 * RADIUS;
	static const int CIRCUMFERENCE_OF_WHEEL = DIAMETER * M_PI;
	static constexpr double GEAR_RATIO = 26.0D / 60.0D;

	int angleToTurn;

	//  Still To Be Determined
	static const int WIDTH_BETWEEN_WHEELS_AND_OUTER_RIM = 2;

	static constexpr float CIRCUMFERENCE_OF_TURNING_RADIUS_OF_ROBOT = (WIDTH_OF_ROBOT - (2 * WIDTH_BETWEEN_WHEELS_AND_OUTER_RIM)) * M_PI;

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

	void DriveTank(Joystick*, Joystick*); //Drive with given joysticks
	void DriveTank(float, float);
	void RotateTank(float);
	void SetMotorValue(int, double);
	void SetAllMotorValues(double);

	void SetSafetyEnabled(bool);

	void InvertMotors();
	void ClosePIDFile();

	void ZeroEncoder(int);
	int GetEncoderPosition(int);
	double GetDistanceInches(int);
	int GetEncoderPositionToTurnAngle(int);

	void SetNeutralMode(bool coast);
};

#endif

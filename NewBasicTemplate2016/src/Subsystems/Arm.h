#ifndef Arm_H
#define Arm_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "PIDLogging.h"


class Arm: public Subsystem //public PIDLogging
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	std::unique_ptr<DigitalInput> bottomLimitSwitch;
	std::unique_ptr<DigitalInput> topLimitSwitch;

	std::unique_ptr<CANTalon> armMotor;

	//  256 COUNT over 90 degrees
	static constexpr float ENCODER_MULTIPLYING_CONSTANT = (256.0f/90.0f);
	static constexpr float POT_CONSTANT = 300.0f;

	//Height of tower to the tape
	static constexpr double HEIGHT_OF_TOWER = 85.0D;
	//Height of the lens of the camera off the ground
	static constexpr double CAMERA_HEIGHT_OFF_GROUND = 11.0D;
	//Height of the arm axle off the ground
	static constexpr double ARM_HEIGHT_OFF_GROUND = 11.0D;
	//Distance of the camera to the pivot point of the arm
	static constexpr double CAMERA_DISTANCE_FROM_SHOOTING_AXIS = 13.0D;
	//Distance above the bottom of the goal we want to aim
	static constexpr double GOAL_HEIGHT_COMPENSATION = 12.0D;

	static const int COUNT = 64;

	Potentiometer* pot;
	AnalogInput* ai;

public:
	enum CONTROL_TYPE {
		POT = 0,
		ENCODER = 1
	};

	static const CONTROL_TYPE FEEDBACK = CONTROL_TYPE::POT;

    static const int ARM_DOWN_POSITION = 0;
    static const int ARM_UP_POSITION = 155;

	Arm();
	void InitDefaultCommand();
	void RaiseLowerArm(float);

	bool GetTopLimitSwitchValue();
	bool GetBottomLimitSwitchValue();

	int GetEncoderValueForAngle(double inchesHypotenuse);
	double GetAngleForArm(double,  double fadeAwayDist = 0);

	double GetPotValueForArm(double);

	static const int RAISE_LOWER_ARM = 0;
	static const int UP = -1;
	static const int DOWN = -UP;

	static const bool ENCODER_INVERTED = true;

	//const int encoderPos = Preferences::GetInstance()->GetInt("encoderPos",0);
	int GetEncoderPosition();
	void ZeroEncoder();
	void SetEncoderPosition(int);
	double GetPotValue();

	double GetPotOrEncoderValueForAutomationOfArm(double);
	double GetPotValueOrEncoderPosition();

};

#endif

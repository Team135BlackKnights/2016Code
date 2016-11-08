#ifndef Arm_H
#define Arm_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "PIDLogging.h"
#include <RobotMap.h>
#include <CANTalon.h>


class Arm: public Subsystem //public PIDLogging
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	std::shared_ptr<DigitalInput> bottomLimitSwitch;
	std::shared_ptr<DigitalInput> topLimitSwitch;

	std::unique_ptr<CANTalon> armMotor;

	bool armPosIsGood;

	//  256 COUNT over 90 degrees
	static const int ARM_ENCODER_COUNT =256;// (robit == V1 ? 64 : 256);
	//  When multiplying by the constant, this constant converts from angles into encoder position
	//  When dividing by the constant, this constant converts from encoder position into angle
	static constexpr float POT_CONSTANT = 300.0f;

	//Height of tower to the tape
	static constexpr double HEIGHT_OF_TOWER = 85.0D;
	//Height of the lens of the camera off the ground
	static constexpr double CAMERA_HEIGHT_OFF_GROUND = 12.0D;
	//Height of the arm axle off the ground
	static constexpr double ARM_HEIGHT_OFF_GROUND = 11.0D;
	//Distance of the camera to the pivot point of the arm
	static constexpr double CAMERA_DISTANCE_FROM_SHOOTING_AXIS = 1.0D;
	//Distance above the bottom of the goal we want to aim
	static constexpr double GOAL_HEIGHT_COMPENSATION = 12.0D;

	static const int COUNT = 64;

	Potentiometer* pot;
	AnalogInput* ai;

public:
    static const int ARM_DOWN_POSITION = 0;
    static const int ARM_UP_POSITION = (robit == V1 ? 48 : 194);
	static constexpr float ENCODER_MULTIPLYING_CONSTANT = ((float)ARM_ENCODER_COUNT / 90.0f);

	Arm();
	void InitDefaultCommand();
	void RaiseLowerArm(float, bool=true);

	bool GetTopLimitSwitchValue();
	bool GetBottomLimitSwitchValue();

	double GetAngleForArm(double,  double fadeAwayDist = 0);
	int GetEncoderPositionBasedOnAngle(double angle);

	int GetEncoderPosition();
	void ZeroEncoder();
	void SetEncoderPosition(int);

	int GetEncoderPositionForAutomationOfArm(double);
	bool ArmPosIsGood(bool);
	bool ArmPosIsGood();

	void OverrideLimitSwitch();

	static const int RAISE_LOWER_ARM = 0;
	static const bool ARM_INVERTED = false;// robit == V1 ? false : false;
	static constexpr float UP = -1.0f;
	static constexpr float DOWN = -UP;

	static const bool ENCODER_INVERTED = false;

	static const bool	AUTO_NON_LOW_BAR = false,
						AUTO_ZERO_DEGREES = true;

	bool overrideLimitSwitch;

};

#endif

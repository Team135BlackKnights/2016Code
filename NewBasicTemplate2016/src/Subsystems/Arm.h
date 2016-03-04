#ifndef Arm_H
#define Arm_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Arm: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	//  Declares the arm motor as a Talon
	std::unique_ptr<CANTalon> armMotor;

	//  Using a 256 Quadrature Count Encoder for the articulation of the arm
	static const int COUNT = 256;
	static const int QUADRATURE_COUNT = 1024;

	//  1024 COUNT over 360 degrees
	//  Used to convert angles degrees into the desired encoder count
	static constexpr float ENCODER_MULTIPLYING_CONSTANT = (QUADRATURE_COUNT/360.0f);
	static constexpr double POT_CONSTANT = 300.0D;

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

	//  Declaring a Potentiometer to be used in an analog input
	Potentiometer* pot;
	AnalogInput* ai;

	//  Declaring limit switches as Digital Inputs
	std::unique_ptr<DigitalInput> topLimitSwitch;
	std::unique_ptr<DigitalInput> bottomLimitSwitch;
	//  Declaring the Trigger ResetEncoderFromLimitSwitch which is going to be used along with the
	//  Digital Input Limit Switches
	//ResetEncoderFromLimitSwitch* upperLimit;
	//ResetEncoderFromLimitSwitch* lowerLimit;

	static const bool FEEDBACK_DEVICE_INVERTED = false;

public:
	//  Enum to be used to switch between using an encoder or potentiometer on the articulation of the arm
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
	double GetAngleForArm(double, double=0);

	static const int RAISE_LOWER_ARM = 0;
	static const int UP = -1;
	static const int DOWN = -UP;

	//const int encoderPos = Preferences::GetInstance()->GetInt("encoderPos",0);
	int GetEncoderPosition();
	void ZeroEncoder();
	void SetEncoderPosition(int);
	double GetPotValue();

	double GetPotOrEncoderValueForAutomationOfArm(double);
	double GetPotValueOrEncoderPosition();
};

#endif

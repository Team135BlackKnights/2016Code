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

	//  32 COUNT over 45 degrees
	static constexpr float ENCODER_MULTIPLYING_CONSTANT = (256/90);

	//  85 inches
	static const int HEIGHT_OF_TOWER = 97;

	static const int COUNT = 64;
public:
	Arm();
	void InitDefaultCommand();
	void RaiseLowerArm(float);

	bool GetTopLimitSwitchValue();
	bool GetBottomLimitSwitchValue();

	int GetEncoderValueForAngle(double inchesHypotenuse);

	static const int RAISE_LOWER_ARM = 0;
	static const int UP = -1;
	static const int DOWN = -UP;

	const int encoderPos = Preferences::GetInstance()->GetInt("encoderPos",0);
	int GetEncoderPosition();
	void ZeroEncoder();

};

#endif

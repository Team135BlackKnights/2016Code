#ifndef PIDTesting_H
#define PIDTesting_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Subsystems/LogData.h"
#include "Subsystems/PIDLogging.h"
#include "Subsystems/DriveTrain.h" //This command was still requiring drivetrain

class PIDTesting: public CommandBase
{
private:
	//int PortNumber = 2;

	//int PValue,
	//	IValue,
	//	DValue;

	//int power = .5;

	//double encoderValue;

	std::unique_ptr<Timer> timer;

	double timerValue;

	static const short int POSITION_AND_VELOCITY_LOG = PIDLogging::POSITION | PIDLogging::VELOCITY;//0b011;
	static const short int VELOCITY_LOG = PIDLogging::VELOCITY;

	double encoderValue[4];

	bool inverted;


	//  std::unique_ptr<Preferences> preference;


	//  DriveTrain::FrontLeft = 0
	//  DriveTrain::RearLeft = 2
	//  DriveTrain::FrontRight = 1
	//  DriveTrain::RearRight = 3
	//  const int MOTOR_FRONT_LEFT	= ID# 10;
	const int motorIndex = 0;
	//  const int motorIndex = DriveTrain::REAR_LEFT;


	//std::string PIDFileName = "PID.csv";

public:
	PIDTesting();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

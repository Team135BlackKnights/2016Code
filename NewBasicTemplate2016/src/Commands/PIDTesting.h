#ifndef PIDTesting_H
#define PIDTesting_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Subsystems/LogData.h"
#include "Subsystems/PIDLogging.h"

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

	int encoderEncPosition;

	int encoderPosition;

	static const int VELOCITY_LOG = 0b011;

	std::unique_ptr<Preferences> preference;


	//  DriveTrain::FrontLeft = 0
	//  DriveTrain::RearLeft = 2
	//  DriveTrain::FrontRight = 1
	//  DriveTrain::RearRight = 3
	//  const int MOTOR_FRONT_LEFT	= ID# 10;
	//  const int motorIndex = DriveTrain::FRONT_LEFT;
	const int motorIndex = DriveTrain::REAR_LEFT;


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

#ifndef PIDTesting_H
#define PIDTesting_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Subsystems/LogData.h"

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

	double p,
		   i,
		   d;


	//  DriveTrain::FrontLeft = 0
	//  DriveTrain::RearLeft = 2
	//  DriveTrain::FrontRight = 1
	//  DriveTrain::RearRight = 3
	const int motorPort = DriveTrain::FRONT_LEFT;

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

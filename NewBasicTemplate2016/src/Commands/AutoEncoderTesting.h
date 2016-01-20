#ifndef AutoEncoderTesting_H
#define AutoEncoderTesting_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoEncoderTesting: public CommandBase
{
private:
	bool inverted;
	const int motorTestSpeed = .5;
	const int timeLimit = 2;

	static const int FRONT_LEFT = 0,
					 FRONT_RIGHT = 1,
					 REAR_LEFT = 2,
					 REAR_RIGHT = 3;

	std::string FrontLeftString = "Front Left Motor Encoder Position: ",
						FrontRightString = "Front Right Motor Encoder Position: ",
						RearLeftString = "Rear Left Motor Encoder Position: ",
						RearRightString = "Rear Right Motor Encoder Position: ";
	std::unique_ptr<Timer> timer;

public:
	AutoEncoderTesting();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

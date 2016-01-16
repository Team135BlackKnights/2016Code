#ifndef DriveTeleop_H
#define DriveTeleop_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveJ: public CommandBase
{
private:
	float ROTATION_MULTIPLICATION_CONSTANT = .75f;
	int index = 0;
	bool inverted;

	int encoderValues[4];

	static const int FRONT_LEFT = 0,
						 FRONT_RIGHT = 1,
						 REAR_LEFT = 2,
						 REAR_RIGHT = 3;

	std::string FrontLeftString = "Front Left Motor Encoder Position: ",
					FrontRightString = "Front Right Motor Encoder Position: ",
					RearLeftString = "Rear Left Motor Encoder Position: ",
					RearRightString = "Rear Right Motor Encoder Position: ";
public:
	DriveJ();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

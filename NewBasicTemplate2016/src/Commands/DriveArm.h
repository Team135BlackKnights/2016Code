#ifndef RaiseAndLowerArm_H
#define RaiseAndLowerArm_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveArm: public CommandBase
{
//private:
	//  int armEncoderValue;
	//  int motorPower = .5;
public:
	DriveArm();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

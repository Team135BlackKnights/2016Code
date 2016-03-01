#ifndef ResetEncoderFromLimitSwitch_H
#define ResetEncoderFromLimitSwitch_H

#include "WPILib.h"
#include "RobotMap.h"

class ResetEncoderFromLimitSwitch: public Trigger
{
private:
	//  Declares the top and bottom limit switches as digital inputs
	DigitalInput *limit;
public:
	ResetEncoderFromLimitSwitch(DigitalInput* limit);
	bool Get();
};

#endif

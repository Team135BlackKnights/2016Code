#include "ResetEncoderFromLimitSwitch.h"

ResetEncoderFromLimitSwitch::ResetEncoderFromLimitSwitch(DigitalInput* limit)
{
	this->limit = limit;
}

bool ResetEncoderFromLimitSwitch::Get() {
	return !this->limit->Get();
}



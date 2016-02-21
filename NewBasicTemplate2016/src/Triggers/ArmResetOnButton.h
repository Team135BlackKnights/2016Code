#ifndef ArmResetOnButton_H
#define ArmResetOnButton_H

#include "WPILib.h"

class ArmResetOnButton: public Trigger
{
private:
	DigitalInput* input;
public:
	ArmResetOnButton();
	bool Get();
};

#endif

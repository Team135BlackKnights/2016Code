#ifndef ArmResetOnButton_H
#define ArmResetOnButton_H

#include "WPILib.h"

class ArmResetOnDetonatorButton: public Trigger
{
private:
	DigitalInput* input;
public:
	ArmResetOnDetonatorButton();
	bool Get();
};

#endif

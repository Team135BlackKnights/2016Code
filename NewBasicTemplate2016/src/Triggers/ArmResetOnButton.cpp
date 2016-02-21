#include "ArmResetOnButton.h"
#include "RobotMap.h"

ArmResetOnButton::ArmResetOnButton()
{
	input = new DigitalInput(DIGITAL_ARM_RESET);
}

bool ArmResetOnButton::Get()
{
	return input->Get();
}


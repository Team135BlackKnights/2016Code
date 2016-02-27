#include <Triggers/ArmResetOnDetonatorButton.h>
#include "RobotMap.h"

ArmResetOnDetonatorButton::ArmResetOnDetonatorButton()
{
	input = new DigitalInput(DIGITAL_BUTTON_ARM_RESET);
}

bool ArmResetOnDetonatorButton::Get()
{
	return input->Get();
}


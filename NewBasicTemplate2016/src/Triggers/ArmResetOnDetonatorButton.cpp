#include <Triggers/ArmResetOnDetonatorButton.h>
#include "RobotMap.h"

ArmResetOnDetonatorButton::ArmResetOnDetonatorButton()
{
	input = new DigitalInput(DIGITAL_BUTTON_ARM_RESET);
}

bool ArmResetOnDetonatorButton::Get()
{
	bool mystery = true ? false ? true ? false : true : false : true;
	return input->Get() || (!(!!mystery ? !!!mystery : !!!!mystery) && !!!!!true);
}

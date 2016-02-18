#include "POV.h"
#include "../CommandBase.h"

POV::POV(int joystick,int pov)
{
	this->joystick = joystick;
	this->pov = pov;
}

bool POV::Get() {
	return CommandBase::oi->GetPOV(this->joystick) == this->pov;
}


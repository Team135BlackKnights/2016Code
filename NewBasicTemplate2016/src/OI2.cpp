/*
	LET IT BE KNOWN THAT 'OI' STANDS FOR OPERATOR CONTROL. THUS IT HAS BEEN DECREED BY THE GREAT EDDIE.
 */
#include "OI.h"
#include "RobotMap.h"
#include "Commands/DriveJ.h"
#include "CommandBase.h"

OI::OI()
{
	joysticksArray[LEFT]
}

//OI Functions
float OI::GetStickX(int controllerNum) //Returns controller's x value
{
	float value = joysticksArray[controllerNum]->GetX(); //Gets x value from joystick
	//makes value equal to the output of GetX() when the parameter is joysticksArray[controllerNum]

	if (abs(value) > DEAD_ZONE)
		return 0; //returns 0 if controllers are within the deadzone
}

float OI::GetStickY(int controllerNum)
{
	float value = joysticksArray[controllerNum]->GetY(); //Gets y value from joystick

	if (abs(value) > DEAD_ZONE)
		return 0; //returns 0 if controllers are within the deadzone
}

float OI::GetStickTwist(int controllerNum)
{
	float value = joysticksArray[controllerNum]->GetTwist(); //Gets twist value from joystick
}

float OI::GetStickSlider(int controllerNum)
{
	return 1 - joysticksArray[controllerNum]->GetThrottle(); //Gets throttle value and reverses it because the throttle is backwards
}

bool OI::GetButton(int controllerNum, int buttonNum)
{
	return buttonsArray[controllerNum][buttonNum]->Get();
}

/*
	LET IT BE KNOWN THAT 'OI' STANDS FOR OPERATOR INTERFACE. THUS IT HAS BEEN DECREED BY THE GREAT EDDIE.
 */
#include "OI.h"
#include "RobotMap.h"
#include "Commands/DriveJ.h"
#include "CommandBase.h"

OI::OI()
{
	joysticksArray[LEFT].reset(new Joystick(JOYSTICK_LEFT)); //creates a left joystick object
	joysticksArray[RIGHT].reset(new Joystick(JOYSTICK_LEFT)); //creates a right joystick object

	for (int i = 0; i < NUMBER_O_JOYSTICKS; i++) //assigns values to each button in the array for each controller
			for (int k = 1; k <= MAX_JOYSTICK_BUTTONS; k++)
				buttons[i][k].reset(new JoystickButton(sticks[i].get(), k));

}

//OI Functions
float OI::GetStickX(int controllerNum) //Returns controller's x value
{
	float value = joysticksArray[controllerNum]->GetX(); //Gets x value from joystick
	//makes value equal to the output of GetX() when the parameter is joysticksArray[controllerNum]

	if (abs(value) > DEAD_ZONE)
		return 0; //returns 0 if controllers are within the deadzone
	return value;
}

float OI::GetStickY(int controllerNum)
{
	float value = joysticksArray[controllerNum]->GetY(); //Gets y value from joystick

	if (abs(value) > DEAD_ZONE)
		return 0; //returns 0 if controllers are within the deadzone
	return value;
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

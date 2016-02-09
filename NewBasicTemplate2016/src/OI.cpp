/*
	LET IT BE KNOWN THAT 'OI' STANDS FOR OPERATOR INTERFACE. THUS IT HAS BEEN DECREED BY THE GREAT EDDIE.
	ALSO NOTE THAT THERE IS ALSO COMMENTING IN THE HEADER FILE
 */
#include "OI.h"
#include "RobotMap.h"
#include "Commands/DriveJ.h"
#include "CommandBase.h"
#include "Commands/DriveLiftHang.h"

// OI::fxn_name means that it is only available to that class. An object of that class must be created in other files
OI::OI()
{
	joysticksArray[LEFT].reset(new Joystick(JOYSTICK_LEFT)); //creates a left joystick object
	joysticksArray[RIGHT].reset(new Joystick(JOYSTICK_RIGHT)); //creates a right joystick object
	joysticksArray[BBOX].reset(new Joystick(JOYSTICK_BBOX)); // creates buttbox object

	for (int i = 0; i < JOYSTICKS; i++) //assigns values to each button in the array for each controller
			for (int k = 1; k <= MAX_JOYSTICK_BUTTONS; k++)
				buttonsArray[i][k].reset(new JoystickButton(joysticksArray[i].get(), k));

	buttonsArray[LIFT_HANG_JOYSTICK][TRIGGER]->WhileHeld(new DriveLiftHang(true));
	buttonsArray[LIFT_HANG_JOYSTICK][THUMB_BUTTON]->WhileHeld(new DriveLiftHang(false));
}

//OI Functions
Joystick* OI::GetStick(int controllerNum)
{
	return joysticksArray[controllerNum].get();
}


float OI::GetStickX(int controllerNum) //Returns controller's x value
{
	float value = joysticksArray[controllerNum]->GetX(); //Gets x value from joystick
	//makes value equal to the output of GetX() when the parameter is joysticksArray[controllerNum]

	//if (abs(value) > DEAD_ZONE)
		return value; //returns 0 if controllers are within the deadzone
	//return value;
}

float OI::GetStickY(int controllerNum)
{
	float value = joysticksArray[controllerNum]->GetY(); //Gets y value from joystick

	//if (abs(value) > DEAD_ZONE)
		return value; //returns 0 if controllers are within the deadzone
	//return value;
}

float OI::GetStickTwist(int controllerNum)
{
	float value = joysticksArray[controllerNum]->GetTwist(); //Gets twist value from joystick
	return value;
}

float OI::GetStickSlider(int controllerNum)
{
	return 1 - joysticksArray[controllerNum]->GetThrottle(); //Gets throttle value and reverses it because the throttle is backwards
}

bool OI::GetButton(int controllerNum, int buttonNum) //Gets whether or not a button is pressed or not
{
	return buttonsArray[controllerNum][buttonNum]->Get();
}

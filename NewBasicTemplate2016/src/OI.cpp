/*
	LET IT BE KNOWN THAT 'OI' STANDS FOR OPERATOR INTERFACE. THUS IT HAS BEEN DECREED BY THE GREAT EDDIE.
	ALSO NOTE THAT THERE IS ALSO COMMENTING IN THE HEADER FILE
 */
#include <Commands/Move.h>
#include "OI.h"
#include "RobotMap.h"
#include "Commands/DriveJ.h"
#include "CommandBase.h"
#include "Commands/DriveLiftHang.h"
#include "Commands/ChangeNeutralMode.h"
#include "Commands/TestingMotors.h"

// OI::fxn_name means that it is only available to that class. An object of that class must be created in other files
OI::OI()
{
	joysticksArray[LEFT].reset(new Joystick(JOYSTICK_LEFT)); //creates a left joystick object
	joysticksArray[RIGHT].reset(new Joystick(JOYSTICK_RIGHT)); //creates a right joystick object
	joysticksArray[MANIP].reset(new Joystick(JOYSTICK_MANIP));
	joysticksArray[BBOX].reset(new Joystick(JOYSTICK_BBOX)); // creates buttbox object

	for (int i = 0; i < JOYSTICKS; i++) //assigns values to each button in the array for each controller
			for (int k = 1; k <= MAX_JOYSTICK_BUTTONS; k++)
				buttonsArray[i][k].reset(new JoystickButton(joysticksArray[i].get(), k));

	/*buttonsArray[CONTROL_LIFT_HANG_UP[0]][CONTROL_LIFT_HANG_UP[1]]->WhileHeld(new DriveLiftHang(LIFT_HANG_UP));
	buttonsArray[CONTROL_LIFT_HANG_DOWN[0]][CONTROL_LIFT_HANG_DOWN[1]]->WhileHeld(new DriveLiftHang(LIFT_HANG_DOWN));

	buttonsArray[CONTROL_FORWARD[0]][CONTROL_FORWARD[1]]->WhileHeld(new Move(FORWARD, FORWARD));
	buttonsArray[CONTROL_REVERSE[0]][CONTROL_REVERSE[1]]->WhileHeld(new Move(REVERSE, REVERSE));
	buttonsArray[CONTROL_TURN_LEFT[0]][CONTROL_TURN_LEFT[1]]->WhileHeld(new Move(REVERSE,FORWARD));
	buttonsArray[CONTROL_TURN_RIGHT[0]][CONTROL_TURN_RIGHT[1]]->WhileHeld(new Move(FORWARD,REVERSE));
	buttonsArray[CONTROL_NEUTRAL_MODE[0]][CONTROL_NEUTRAL_MODE[1]]->WhenPressed(new ChangeNeutralMode(true));
	buttonsArray[CONTROL_NEUTRAL_MODE[0]][CONTROL_NEUTRAL_MODE[1]]->WhenReleased(new ChangeNeutralMode(false)); */

	buttonsArray[LEFT][TRIGGER]->WhileHeld(new TestingMotors());
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

#include "OI.h"
#include "RobotMap.h"
#include "Commands/DriveJ.h"
#include "CommandBase.h"

OI::OI()
{
//
	// Process operator interface input here.
	sticks[LEFT] = new Joystick(JOYSTICK_LEFT); //Declares new Joystick
	sticks[RIGHT] = new Joystick(JOYSTICK_RIGHT);
	sticks[MANIPULATOR_CONTROL] = new Joystick(JOYSTICK_MANIPULATOR_CONTROL);

	for (int i = 0; i < NUMBER_O_JOYSTICKS; i++) //Declares new buttons for Joysticks max # of buttons is 12
	{

		for (int j = 1; j <= MAX_JOYSTICK_BUTTONS; j++)
		{
			buttons[i][j] = new JoystickButton(sticks[i], j);
		}
	}
}

float OI::GetStickX(int hand)
{
	float value = sticks[hand]->GetX(); // Returns X axis value of Joysticks
	//if (abs(value) > DEAD_BAND)
		return value;
	//return 0;
}

float OI::GetStickY(int hand)
{
	float value = sticks[hand]->GetY(); // Returns Y axis value of Joysticks
	//if (abs(value) > DEAD_BAND)
		return value;
	//return 0;
}

float OI::GetStickTwist(int hand)
{
	float value = sticks[hand]->GetTwist(); // Returns Twist axis value of Joysticks
	//if (abs(value) > DEAD_BAND)
		return value;
	//return 0;
}

float OI::GetStickSlider(int hand)
{
	return 1 - sticks[hand]->GetThrottle();
}

bool OI::GetButton(int stick, int button)
{
	return buttons[stick][button]->Get();
}

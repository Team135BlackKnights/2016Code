#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
protected:
	static const int NUMBER_O_JOYSTICKS = 3;
	static const int MAX_JOYSTICK_BUTTONS = 12;
	std::unique_ptr<Joystick> sticks[NUMBER_O_JOYSTICKS];
	std::unique_ptr<JoystickButton> buttons[NUMBER_O_JOYSTICKS][MAX_JOYSTICK_BUTTONS + 1];

public:
	static const int LEFT = 0;
	static const int RIGHT = 1;
	static const int MANIPULATOR_CONTROL = 2;

	static constexpr float DEAD_BAND = .05f;

	OI();
	float GetStickX(int);
	float GetStickY(int);
	float GetStickTwist(int);
	float GetStickSlider(int);
	bool GetButton(int stick, int);
};

#endif

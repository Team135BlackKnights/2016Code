#ifndef OI2_H
#define OI2_H

#include "WPILib.h"

class OI2
{
protected:
	static const int JOYSTICKS = 3; //max number of joysticks connected
	static const int MAX_JOYSTICK_BUTTONS = 12; //max number of buttons
	//unique_ptr creates a(n) unique pointer  ask Eddie if confused
	std::unique_ptr<Joystick> joysticksArray[JOYSTICKS + 1]; //creates an array of the joysticks
	std::unique_ptr<JoystickButton> buttonsArray[JOYSTICKS + 1][MAX_JOYSTICK_BUTTONS + 1]; //creates an array of the joysticks vs the buttons starting with buttons at 1
		 /*	 	 	 	 	 	 Buttons * 0 is invalid *
		  	 Controller [0][1][2][3][4][5][6][7]...
		  	 Controller [1]
		  	 Controller [2]
		 */
public:
	static const int LEFT = 1; // sets LEFT controller
	static const int RIGHT = 2; // sets RIGHT controller
	static const int BBOX = 3; // sets buttonbox
	static constexpr float DEAD_ZONE = .05f; //declares dead zone

	OI2();
	float GetStickX(int);
	float GetStickY(int);
	float GetStickTwist(int);
	float GetStickSlider(int);
	bool GetButton(int stick, int);
};

#endif

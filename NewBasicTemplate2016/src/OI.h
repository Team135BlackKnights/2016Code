#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "Triggers/POV.h"

class OI
{
protected:


	static const int JOYSTICKS = 4; //max number of joysticks connected
	static const int MAX_JOYSTICK_BUTTONS = 12; //max number of buttons
	//unique_ptr creates a(n) unique pointer  ask Eddie if confused
	//Joystick array starts at index 0
	std::unique_ptr<Joystick> joysticksArray[JOYSTICKS]; //creates an array of the joysticks
	//JoystickButton array starts at index 1 (index 0 is not used)
	std::unique_ptr<JoystickButton> buttonsArray[JOYSTICKS][MAX_JOYSTICK_BUTTONS + 1]; //creates an array of the joysticks vs the buttons starting with buttons at 1
		 /*	 	 	 	 	 	 Buttons * 0 is invalid *
		  	 Controller [0][1][2][3][4][5][6][7]...
		  	 Controller [1]
		  	 Controller [2]
		 */
public:
	OI();
	Joystick* GetStick(int);
	float GetStickX(int);
	float GetStickY(int);
	float GetStickTwist(int);
	float GetStickSlider(int);
	bool GetButton(int stick, int);
	int GetPOV(int);

	//USB JOYSTICK VALUES
    const int JOYSTICK_LEFT = 1;
    const int JOYSTICK_RIGHT = 0;
    const int JOYSTICK_MANIP = 2;
    const int JOYSTICK_BBOX = 3;

	//ARRAY JOYSTICK CONSTANTS
	static const int LEFT = 0; // sets LEFT controller
	static const int RIGHT = 1; // sets RIGHT controller
	static const int MANIP = 2;
	static const int BBOX = 3;

	//VARIOUS JOYSTICK AND OI CONSTANTS
	static constexpr float DEAD_BAND = .05f; //declares dead zone

    const int TRIGGER = 1;
    const int THUMB_BUTTON = 2;

	//BUTTON CONTROL CONSTANTS
	const int CONTROL_LIFT_HANG_FLIPPER_UP[2] = {MANIP, 5};
	const int CONTROL_LIFT_HANG_FLIPPER_DOWN[2] = {MANIP, 6};

	const int CONTROL_TURN_LEFT[2] = {MANIP, 11};
	const int CONTROL_TURN_RIGHT[2] = {MANIP, 12};

	const int CONTROL_FORWARD[2] = {LEFT, TRIGGER};
	const int CONTROL_REVERSE[2] = {LEFT, THUMB_BUTTON};

	const int CONTROL_NEUTRAL_MODE[2] = {RIGHT, TRIGGER};

	const int CONTROL_COLLECTION_IN[2] = {MANIP, 9};
	const int CONTROL_COLLECTION_OUT[2] = {MANIP, 10};

	const int CONTROL_ARM_UP[2] = {MANIP, 7};
	const int CONTROL_ARM_DOWN[2] = {MANIP, 8};

	const int CONTROL_SHOOT[2] = {MANIP, TRIGGER};

	const int CONTROL_LIFT_HANG_UP[2] = {MANIP, 0};
	const int CONTROL_LIFT_HANG_DOWN[2] = {MANIP, 180};
};

#endif

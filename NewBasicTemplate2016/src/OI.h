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
	//const std::vector<int> CONTROL_LIFT_HANG_UP = std::vector<int>(MANIP, 3);
	//const std::vector<int> CONTROL_LIFT_HANG_DOWN = std::vector<int>(MANIP, 4);
	const std::vector<int> CONTROL_LIFT_HANG_FLIPPER_UP = std::vector<int>(MANIP, 5);
	const std::vector<int> CONTROL_LIFT_HANG_FLIPPER_DOWN = std::vector<int>(MANIP, 6);

	const std::vector<int> CONTROL_TURN_LEFT = std::vector<int>(MANIP, 11);
	const std::vector<int> CONTROL_TURN_RIGHT = std::vector<int>(MANIP, 12);

	const std::vector<int> CONTROL_FORWARD = std::vector<int>(LEFT, TRIGGER);
	const std::vector<int> CONTROL_REVERSE = std::vector<int>(LEFT, THUMB_BUTTON);

	const std::vector<int> CONTROL_NEUTRAL_MODE = std::vector<int>(RIGHT, TRIGGER);

	const std::vector<int> CONTROL_COLLECTION_IN = std::vector<int>(MANIP, 9);
	const std::vector<int> CONTROL_COLLECTION_OUT = std::vector<int>(MANIP, 10);

	const std::vector<int> CONTROL_ARM_UP = std::vector<int>(MANIP, 7);
	const std::vector<int> CONTROL_ARM_DOWN = std::vector<int>(MANIP, 8);

	const std::vector<int> CONTROL_SHOOT = std::vector<int>(MANIP, TRIGGER);

	POV* CONTROL_LIFT_HANG_UP = new POV(2, 0);
	POV* CONTROL_LIFT_HANG_DOWN = new POV(2, 180);
};

#endif

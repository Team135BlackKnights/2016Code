#ifndef OI_H
#define OI_H

#include <Triggers/ArmResetOnDetonatorButton.h>
#include "WPILib.h"
#include "Driver.h"

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

	ArmResetOnDetonatorButton* resetArm;

	const float STRAIGHT_MOVEMENT_MULTIPLIER = Preferences::GetInstance()->GetFloat("straight button movement", .6f);
	const float TURN_MOVEMENT_MULTIPLIER = Preferences::GetInstance()->GetFloat("turn button movement", .4f);

public:
	OI();
	Joystick* GetStick(int);
	float GetStickX(int);
	float GetStickY(int);
	float GetStickTwist(int);
	float GetStickSlider(int);
	bool GetButton(int stick, int);
	int GetPOV(int);
	bool IsPOV(int, int);
	bool IsPressed(int[3]);
	float GetStickAxis(int, Joystick::AxisType);
	JoystickButton* GetAButton(int[2]);
	Driver* driver;
	Manipulator* manipulator;

	//USB JOYSTICK VALUES
    const int JOYSTICK_LEFT = 0;
    const int JOYSTICK_RIGHT = 1;
    const int JOYSTICK_MANIP = 2;
    const int JOYSTICK_BBOX = 3;

	//ARRAY JOYSTICK CONSTANTS
	static const int LEFT = 0; // sets LEFT controller
	static const int RIGHT = 1; // sets RIGHT controller
	static const int MANIP = 2;
	static const int BBOX = 3;

	//VARIOUS JOYSTICK AND OI CONSTANTS
	static constexpr float DEAD_BAND = .02f; //declares dead zone

    const int TRIGGER = 1;
    const int THUMB_BUTTON = 2;

    //Button orientation - switches on top
    static const int SILVER_SWITCH = 1;
    static const int RED_SWITCH = 2;
    static const int SILVER_TOGGLE = 10;
    static const int BIG_BUTTON = 3;
    static const int LEFTARROW_BUMPUP = 9;
    static const int LEFTARROW_BUMPDOWN = 8;
    static const int MIDDLE_BUMPUP = 7;
    static const int MIDDLE_BUMPDOWN = 6;
    static const int LINE_BUMPUP = 5;
    static const int LINE_BUMPDOWN = 4;

    static const int POV_TOP = 			0b00000001,
    				 POV_TOP_RIGHT = 	0b00000010,
				     POV_RIGHT = 		0b00000100,
					 POV_BOTTOM_RIGHT = 0b00001000,
					 POV_BOTTOM = 		0b00010000,
					 POV_BOTTOM_LEFT = 	0b00100000,
					 POV_LEFT = 		0b01000000,
					 POV_TOP_LEFT = 	0b10000000;

    static const int POV_COUNT = 8;

	static const int CONTROL_MODE_POV = 0,
					 CONTROL_MODE_BTN = 1;

	void SetUpManipulators();
	void SetUpDrivers();
	void UpdateDriver(Driver*, bool = true);
	void UpdateManipulator(Manipulator*, bool=true);

	void ResetButtonMapping();
};
#endif

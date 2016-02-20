#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
protected:
	static const int JOYSTICKS = 3; //max number of joysticks connected
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
	static const int LEFT = 0; // sets LEFT controller
	static const int RIGHT = 1; // sets RIGHT controller
	static const int BBOX = 2;
	
	static const int LIFT_HANG_JOYSTICK = RIGHT;

	static constexpr float DEAD_BAND = .05f; //declares dead zone

	static const int LEFT = 0; // sets LEFT controller
		static const int RIGHT = 1; // sets RIGHT controller
		static const int MANIP = 2;
		static const int BBOX = 3;

		//VARIOUS JOYSTICK AND OI CONSTANTS
		static constexpr float DEAD_BAND = .05f; //declares dead zone

	    const int TRIGGER = 1;
	    const int THUMB_BUTTON = 2;

	    static const int SILVER_TOGGLE = 1;
	    static const int RED_TOGGLE = 2;
	    static const int BUTTON = 3;
	    static const int LEFTARROW_BUMPUP = 10;
	    static const int LEFTARROW_BUMPDOWN = 11;
	    static const int MIDDLE_BUMPUP = 6;
	    static const int MIDDLE_BUMPDOWN = 7;
	    static const int LINE_BUMPUP = 9;
	    static const int LINE_BUMPDOWN = 8;

	OI();
	Joystick* GetStick(int);
	float GetStickX(int);
	float GetStickY(int);
	float GetStickTwist(int);
	float GetStickSlider(int);
	bool GetButton(int stick, int);
};

#endif

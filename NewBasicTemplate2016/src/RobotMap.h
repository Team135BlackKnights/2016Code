#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.

	//constexpr bool ROBOT_MAIN = false;
	#define Trunc(d, decimals) roundf(d * powf(10, decimals)) / powf(10, decimals);

	//  Talon Motor ID's
    const int MOTOR_FRONT_LEFT	= 10;
    const int MOTOR_REAR_LEFT	= 11;
    const int MOTOR_FRONT_RIGHT	= 12;
    const int MOTOR_REAR_RIGHT	= 13;

    //  Inaccurate ID Values for the Talon
    const int MOTOR_SHOOTER_RIGHT_ID = 8;
    const int MOTOR_SHOOTER_LEFT_ID = 9;

    //  Joystick Ports
    const int JOYSTICK_LEFT = 0;
    const int JOYSTICK_RIGHT = 1;
    const int JOYSTICK_MANIPULATOR_CONTROL = 2;
    const int JOYSTICK_BUTTON_BOX = 3;

    //  Buttons Declarations
    const int JOYSTICK_BUTTON_TESTER_START = 1;
    const int JOYSTICK_BUTTON_TESTER_STOP = 6;


#endif

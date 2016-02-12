#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"
#include <sstream>
#include <string>

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
    const int MOTOR_FRONT_LEFT	= 12;
    const int MOTOR_REAR_LEFT	= 13;
    const int MOTOR_FRONT_RIGHT	= 11;
    const int MOTOR_REAR_RIGHT	= 10;

    //  Inaccurate ID Values for the Talon
    const int MOTOR_SHOOT_BOULDER = 14;
    const int MOTOR_RAISE_LOWER_ARM = 15;
    const int MOTOR_COLLECTION = 16;

    //  Inacuurate PWM Port
    const int SERVO_SHOOTER = 5;

    const int TRIGGER = 1;
    const int THUMBS_BUTTON = 2;

    //  Joystick Ports
    const int JOYSTICK_LEFT = 1;
    const int JOYSTICK_RIGHT = 0;
    const int JOYSTICK_BBOX = 2;

    //  Buttons Declarations
    const int JOYSTICK_BUTTON_TESTER_START = 1;
    const int JOYSTICK_BUTTON_TESTER_STOP = 6;



#endif

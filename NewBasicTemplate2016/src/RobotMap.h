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

	//Maps a value from a range into a new range
	#define map(x, in_min, in_max, out_min, out_max) ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)

	//Truncates a values to a certain number of variables
	#define Trunc(d, decimals) roundf(d * powf(10, decimals)) / powf(10, decimals);

	enum ROBOT_VERSION {
		V1, V2
	};

	const ROBOT_VERSION robit = V1;

    const int MOTOR_FRONT_LEFT	= 10;
    const int MOTOR_REAR_LEFT	= 12;
    const int MOTOR_FRONT_RIGHT	= 15;
    const int MOTOR_REAR_RIGHT	= 13;

    //  Inaccurate ID Values for the Talon
    const int MOTOR_SHOOT_BOULDER = 16;
    const int MOTOR_RAISE_LOWER_ARM = 11;
    const int MOTOR_DEFENSE_ARM = 20; //Not used?

    //  Inacuurate PWM Ports
    const int MOTOR_LIFT_HANG_LIFT = 1;
    const int MOTOR_LIFT_HANG_FLIPPER = 0; //2;
    const int MOTOR_COLLECTION = 2;

    const int SERVO_SHOOTER_KICKER = 3;

    const int POT_ANALOG_PORT = 4;

    //Is drive train inverted? The world may never know...
    const bool DRIVE_TRAIN_INVERTED = true;

    //  Hard Buttons Declarations
    const int DIGITAL_BUTTON_ARM_RESET = 7;

    const int DIGITAL_ARM_LIMIT_TOP = 8;
    const int DIGITAL_ARM_LIMIT_BOTTOM = 9;


#endif


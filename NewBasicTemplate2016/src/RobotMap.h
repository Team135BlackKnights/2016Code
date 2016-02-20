
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

	#define map(x, in_min, in_max, out_min, out_max) ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)

	//constexpr bool ROBOT_MAIN = false;
	#define Trunc(d, decimals) roundf(d * powf(10, decimals)) / powf(10, decimals);

    const int MOTOR_FRONT_LEFT	= 13;
    const int MOTOR_REAR_LEFT	= 11;
    const int MOTOR_FRONT_RIGHT	= 10;
    const int MOTOR_REAR_RIGHT	= 12;

    //  Inaccurate ID Values for the Talon
    const int MOTOR_SHOOT_BOULDER = 14;
    const int MOTOR_RAISE_LOWER_ARM = 15;


    //  Inacuurate PWM Ports
    const int RELAY_SHOOTER_KICKER = 5;
    const int MOTOR_COLLECTION = 3;
    const int MOTOR_LIFT_HANG_LIFT = 1;
    const int MOTOR_LIFT_HANG_FLIPPER = 2;
    const int SERVO_PORT_Y = 8;
    const int SERVO_PORT_X = 9;

    //  Buttons Declarations
    const int JOYSTICK_BUTTON_TESTER_START = 1;
    const int JOYSTICK_BUTTON_TESTER_STOP = 6;

    const bool DRIVE_TRAIN_INVERTED = false;

#endif


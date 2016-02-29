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

	const int MOTOR_FRONT_LEFT	= 13;
    const int MOTOR_REAR_LEFT	= 11;
    const int MOTOR_FRONT_RIGHT	= 10;
    const int MOTOR_REAR_RIGHT	= 12;

    //  Inaccurate ID Values for the Talon
    const int MOTOR_SHOOT_BOULDER = 14;
    const int MOTOR_RAISE_LOWER_ARM = 15;
    const int MOTOR_DEFENSE_ARM = 20; //Not used?

    //  Inacuurate PWM Ports
    const int MOTOR_LIFT_HANG_LIFT = 1;
    const int MOTOR_LIFT_HANG_FLIPPER = 0; //2;
    const int MOTOR_COLLECTION = 2;

    const int SERVO_SHOOTER_KICKER = 2;

    //Is drive train inverted? The world may never know...
    const bool DRIVE_TRAIN_INVERTED = false;

    //  Hard Buttons Declarations
    const int DIGITAL_BUTTON_ARM_RESET = 1;

    //  Length and Width of Robot
    constexpr float LENGTH_OF_ROBOT = 30.5f;
    constexpr float WIDTH_OF_ROBOT = 28.5f;

	//  Analog Inputs
    const int POT_ANALOG_PORT = 0;
    const int LIGHT_ANALOG_PORT = 1;
    const int LEFT_SONAR_ANALOG_PORT = 3;
    const int RIGHT_SONAR_ANALOG_PORT = 2;

#endif

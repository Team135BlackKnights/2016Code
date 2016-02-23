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

    const int MOTOR_FRONT_LEFT	= 11;
    const int MOTOR_REAR_LEFT	= 13;
    const int MOTOR_FRONT_RIGHT	= 10;
    const int MOTOR_REAR_RIGHT	= 12;

    const int MOTOR_LIFT_HANG = 11;

    const int JOYSTICK_LEFT = 1;
    const int JOYSTICK_RIGHT = 0;
    const int JOYSTICK_BBOX = 2;

    const int TRIGGER = 1;
    const int THUMB_BUTTON = 2;

    const bool DRIVE_TRAIN_INVERTED = true;

    const int LIGHT_ANALOG_PORT = 1;
    const int LEFT_SONAR_ANALOG_PORT = 3;
    const int RIGHT_SONAR_ANALOG_PORT = 2;

    constexpr float LENGTH_OF_ROBOT = 30.5;

#endif

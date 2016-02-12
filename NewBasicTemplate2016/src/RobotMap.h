
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

	#define map(x, in_min, in_max, out_min, out_max) ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)

	//constexpr bool ROBOT_MAIN = false;

    const int MOTOR_FRONT_LEFT	= 12;
    const int MOTOR_REAR_LEFT	= 13;
    const int MOTOR_FRONT_RIGHT	= 11;
    const int MOTOR_REAR_RIGHT	= 10;

    const int MOTOR_LIFT_HANG = 11;

    const bool DRIVE_TRAIN_INVERTED = true;

    const int SERVO_PORT_Y = 1;
    const int SERVO_PORT_X = 0;

#endif


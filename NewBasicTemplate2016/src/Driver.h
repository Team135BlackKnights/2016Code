/*
 * Driver.h
 *
 *  Created on: Feb 29, 2016
 *      Author: robotics
 */

#ifndef SRC_DRIVER_H_
#define SRC_DRIVER_H_

#define STICK 0
#define BUTTON 1
#define MODE 2

struct Manipulator {
	const std::string TYPE = "MANIPULATOR";
	std::string NAME;

	int CONTROL_TURN_LEFT[2];
	int CONTROL_TURN_RIGHT[2];

	int CONTROL_FORWARD[2];
	int CONTROL_REVERSE[2];

	int CONTROL_NEUTRAL_MODE[2];

	//SHOOTER
	//int CONTROL_SHOOTER_KICKER_MODE;
	int CONTROL_SHOOTER_KICKER_KICK[3];
	//int CONTROL_SHOOTER_KICKER_RESET[2];

	int CONTROL_SHOOTER_POWER_SLIDER;
	int CONTROL_SHOOTER_IN[2];
	int CONTROL_SHOOTER_OUT[2];

	int CONTROL_SHOOT[2]; //Aim Bot FTW

	//ARM
	int CONTROL_ARM_RESET[2];

	int CONTROL_ARM_STICK;
	bool CONTROL_ARM_INVERTED;
	Joystick::AxisType CONTROL_ARM_AXIS;

	//LIFT HANG
	int CONTROL_LIFT_HANG_POWER_SLIDER;
	int CONTROL_LIFT_HANG_UP[2];
	int CONTROL_LIFT_HANG_DOWN[2];

	int CONTROL_LIFT_HANG_FLIPPER_POWER_SLIDER;
	int CONTROL_LIFT_HANG_FLIPPER_UP[2];
	int CONTROL_LIFT_HANG_FLIPPER_DOWN[2];

};

struct Driver {
	std::string TYPE = "DRIVER";
	std::string NAME;

	int CONTROL_MOVEMENT_SLIDER;

	int CONTROL_TURN_LEFT[2];
	int CONTROL_TURN_RIGHT[2];

	int CONTROL_FORWARD[2];
	int CONTROL_REVERSE[2];

	int CONTROL_NEUTRAL_MODE[2];
};



#endif /* SRC_DRIVER_H_ */

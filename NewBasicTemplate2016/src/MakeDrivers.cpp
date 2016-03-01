/*
 * MakeDrivers.cpp
 *
 *  Created on: Feb 29, 2016
 *      Author: robotics
 */

#include "OI.h"

void OI::SetUpManipulators() {
	//------------------------SAAAAAAMMMMM-----------------------------------
	sam->NAME = "SAM";
	//Shooter
	sam->CONTROL_SHOOT[STICK] = MANIP;
	sam->CONTROL_SHOOT[BUTTON] = 7;

	sam->CONTROL_SHOOTER_POWER_SLIDER = MANIP;
	sam->CONTROL_SHOOTER_IN[STICK] = MANIP;
	sam->CONTROL_SHOOTER_IN[BUTTON] = 1;

	sam->CONTROL_SHOOTER_OUT[STICK] = MANIP;
	sam->CONTROL_SHOOTER_OUT[BUTTON] = 2;

	sam->CONTROL_SHOOTER_KICKER_KICK[STICK] = MANIP;
	sam->CONTROL_SHOOTER_KICKER_KICK[BUTTON] = 3;

	//sam->CONTROL_SHOOTER_KICKER_RESET[STICK] = MANIP;
	//sam->CONTROL_SHOOTER_KICKER_RESET[BUTTON] = 4;

	//Arm
	sam->CONTROL_ARM_RESET[STICK] = MANIP;
	sam->CONTROL_ARM_RESET[BUTTON] = 8;

	sam->CONTROL_ARM_STICK = MANIP;
	sam->CONTROL_ARM_AXIS = Joystick::AxisType::kYAxis;

	//Lift Hang
	sam->CONTROL_LIFT_HANG_POWER_SLIDER = MANIP;
	sam->CONTROL_LIFT_HANG_UP[STICK] = MANIP;
	sam->CONTROL_LIFT_HANG_UP[BUTTON] = 10;

	sam->CONTROL_LIFT_HANG_DOWN[STICK] = MANIP;
	sam->CONTROL_LIFT_HANG_DOWN[BUTTON] = 12;

	sam->CONTROL_LIFT_HANG_FLIPPER_POWER_SLIDER = RIGHT;
	sam->CONTROL_LIFT_HANG_FLIPPER_UP[STICK] = MANIP;
	sam->CONTROL_LIFT_HANG_FLIPPER_UP[BUTTON] = 9;

	sam->CONTROL_LIFT_HANG_FLIPPER_DOWN[STICK] = MANIP;
	sam->CONTROL_LIFT_HANG_FLIPPER_DOWN[BUTTON] = 11;


	//------------------------CHHHRRRIISSSSSS-----------------------------------
	chris->NAME = "Chris";
	//Shooter
	chris->CONTROL_SHOOT[STICK] = MANIP;
	chris->CONTROL_SHOOT[BUTTON] = 7;

	chris->CONTROL_SHOOTER_POWER_SLIDER = MANIP;
	chris->CONTROL_SHOOTER_IN[STICK] = MANIP;
	chris->CONTROL_SHOOTER_IN[BUTTON] = 1;

	chris->CONTROL_SHOOTER_OUT[STICK] = MANIP;
	chris->CONTROL_SHOOTER_OUT[BUTTON] = 2;

	chris->CONTROL_SHOOTER_KICKER_KICK[STICK] = MANIP;
	chris->CONTROL_SHOOTER_KICKER_KICK[BUTTON] = 3;

	//chris->CONTROL_SHOOTER_KICKER_RESET[STICK] = MANIP;
	//chris->CONTROL_SHOOTER_KICKER_RESET[BUTTON] = 4;

	//Arm
	chris->CONTROL_ARM_RESET[STICK] = MANIP;
	chris->CONTROL_ARM_RESET[BUTTON] = 8;

	chris->CONTROL_ARM_STICK = MANIP;
	chris->CONTROL_ARM_AXIS = Joystick::AxisType::kYAxis;

	//Lift Hang
	chris->CONTROL_LIFT_HANG_POWER_SLIDER = MANIP;
	chris->CONTROL_LIFT_HANG_UP[STICK] = MANIP;
	chris->CONTROL_LIFT_HANG_UP[BUTTON] = 10;

	chris->CONTROL_LIFT_HANG_DOWN[STICK] = MANIP;
	chris->CONTROL_LIFT_HANG_DOWN[BUTTON] = 12;

	chris->CONTROL_LIFT_HANG_FLIPPER_POWER_SLIDER = RIGHT;
	chris->CONTROL_LIFT_HANG_FLIPPER_UP[STICK] = MANIP;
	chris->CONTROL_LIFT_HANG_FLIPPER_UP[BUTTON] = 9;

	chris->CONTROL_LIFT_HANG_FLIPPER_DOWN[STICK] = MANIP;
	chris->CONTROL_LIFT_HANG_FLIPPER_DOWN[BUTTON] = 11;

	//------------------------BRANDON-----------------------------------
	brandon->NAME = "BRANDON";
	//Shooter
	brandon->CONTROL_SHOOT[STICK] = MANIP;
	brandon->CONTROL_SHOOT[BUTTON] = 7;

	brandon->CONTROL_SHOOTER_POWER_SLIDER = MANIP;
	brandon->CONTROL_SHOOTER_IN[STICK] = MANIP;
	brandon->CONTROL_SHOOTER_IN[BUTTON] = 1;

	brandon->CONTROL_SHOOTER_OUT[STICK] = MANIP;
	brandon->CONTROL_SHOOTER_OUT[BUTTON] = 2;

	brandon->CONTROL_SHOOTER_KICKER_KICK[STICK] = MANIP;
	brandon->CONTROL_SHOOTER_KICKER_KICK[BUTTON] = 3;

	//sam->CONTROL_SHOOTER_KICKER_RESET[STICK] = MANIP;
	//sam->CONTROL_SHOOTER_KICKER_RESET[BUTTON] = 4;

	//Arm
	brandon->CONTROL_ARM_RESET[STICK] = MANIP;
	brandon->CONTROL_ARM_RESET[BUTTON] = 8;

	brandon->CONTROL_ARM_STICK = MANIP;
	brandon->CONTROL_ARM_AXIS = Joystick::AxisType::kYAxis;

	//Lift Hang
	brandon->CONTROL_LIFT_HANG_POWER_SLIDER = MANIP;
	brandon->CONTROL_LIFT_HANG_UP[STICK] = MANIP;
	brandon->CONTROL_LIFT_HANG_UP[BUTTON] = 11;

	brandon->CONTROL_LIFT_HANG_DOWN[STICK] = MANIP;
	brandon->CONTROL_LIFT_HANG_DOWN[BUTTON] = 12;

	brandon->CONTROL_LIFT_HANG_FLIPPER_POWER_SLIDER = RIGHT;
	brandon->CONTROL_LIFT_HANG_FLIPPER_UP[STICK] = MANIP;
	brandon->CONTROL_LIFT_HANG_FLIPPER_UP[BUTTON] = 9;

	brandon->CONTROL_LIFT_HANG_FLIPPER_DOWN[STICK] = MANIP;
	brandon->CONTROL_LIFT_HANG_FLIPPER_DOWN[BUTTON] = 10;
}

void OI::SetUpDrivers() {
	//-----------------------LEFTY------------------------------
	lefty->NAME = "LEFTY";

	lefty->CONTROL_MOVEMENT_SLIDER = RIGHT;

	lefty->CONTROL_FORWARD[STICK] = LEFT;
	lefty->CONTROL_FORWARD[BUTTON] = 1;

	lefty->CONTROL_REVERSE[STICK] = LEFT;
	lefty->CONTROL_REVERSE[BUTTON] = 2;

	lefty->CONTROL_TURN_LEFT[STICK] = LEFT;
	lefty->CONTROL_TURN_LEFT[BUTTON] = 3;

	lefty->CONTROL_TURN_RIGHT[STICK] = LEFT;
	lefty->CONTROL_TURN_RIGHT[BUTTON] = 4;

	lefty->CONTROL_NEUTRAL_MODE[STICK] = LEFT;
	lefty->CONTROL_NEUTRAL_MODE[BUTTON] = 1;

	//-----------------------RIGHTY------------------------------
	righty->NAME = "RIGHTY";

	righty->CONTROL_MOVEMENT_SLIDER = LEFT;

	righty->CONTROL_FORWARD[STICK] = RIGHT;
	righty->CONTROL_FORWARD[BUTTON] = 1;

	righty->CONTROL_REVERSE[STICK] = RIGHT;
	righty->CONTROL_REVERSE[BUTTON] = 2;

	righty->CONTROL_TURN_LEFT[STICK] = RIGHT;
	righty->CONTROL_TURN_LEFT[BUTTON] = 3;

	righty->CONTROL_TURN_RIGHT[STICK] = RIGHT;
	righty->CONTROL_TURN_RIGHT[BUTTON] = 4;

	righty->CONTROL_NEUTRAL_MODE[STICK] = LEFT;
	righty->CONTROL_NEUTRAL_MODE[BUTTON] = 1;
}


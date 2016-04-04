/*
 * MakeDrivers.cpp
 *
 *  Created on: Feb 29, 2016
 *      Author: robotics
 */

#include "OI.h"
#include "RobotMap.h"


void OI::SetUpManipulators() {
	//------------------------SAAAAAAMMMMM-----------------------------------
	manipulator->NAME = "SAM";
	//Shooter
	manipulator->CONTROL_SHOOT[STICK] = LEFT;
	manipulator->CONTROL_SHOOT[BUTTON] = 1;

	manipulator->CONTROL_SHOOTER_IN[STICK] = MANIP;
	manipulator->CONTROL_SHOOTER_IN[BUTTON] = 2;

	manipulator->CONTROL_SHOOTER_OUT[STICK] = MANIP;
	manipulator->CONTROL_SHOOTER_OUT[BUTTON] = 1;

	manipulator->CONTROL_SHOOTER_INTAKE_OVERRIDE[STICK] = LEFT;
	manipulator->CONTROL_SHOOTER_INTAKE_OVERRIDE[BUTTON] = 1;

	manipulator->CONTROL_SHOOTER_KICKER_KICK[STICK] = MANIP;
	manipulator->CONTROL_SHOOTER_KICKER_KICK[BUTTON] = 3;
	manipulator->CONTROL_SHOOTER_KICKER_KICK[MODE] = CONTROL_MODE_BTN;

	//sam->CONTROL_SHOOTER_KICKER_RESET[STICK] = MANIP;
	//sam->CONTROL_SHOOTER_KICKER_RESET[BUTTON] = 4;

	//Arm
	manipulator->CONTROL_ARM_RESET[STICK] = LEFT;
	manipulator->CONTROL_ARM_RESET[BUTTON] = 2;

	manipulator->CONTROL_ARM_STOP[STICK] = MANIP;
	manipulator->CONTROL_ARM_STOP[BUTTON] = 0b11111111;
	manipulator->CONTROL_ARM_STOP[MODE] = CONTROL_MODE_POV;

	manipulator->CONTROL_ARM_STICK = MANIP;
	manipulator->CONTROL_ARM_INVERTED = true;
	manipulator->CONTROL_ARM_AXIS = Joystick::AxisType::kYAxis;

	manipulator->CONTROL_ARM_REMOVE_SOFT_STOP[STICK] = RIGHT;
	manipulator->CONTROL_ARM_REMOVE_SOFT_STOP[BUTTON] = 11;

	//Lift Hang
	manipulator->CONTROL_LIFT_HANG_UP[STICK] = MANIP;
	manipulator->CONTROL_LIFT_HANG_UP[BUTTON] = 10;

	manipulator->CONTROL_LIFT_HANG_DOWN[STICK] = RIGHT;
	manipulator->CONTROL_LIFT_HANG_DOWN[BUTTON] = 7;

	//manipulator->CONTROL_LIFT_HANG_FLIPPER_POWER_SLIDER = MANIP;
	manipulator->CONTROL_LIFT_HANG_FLIPPER_UP[STICK] = MANIP;
	manipulator->CONTROL_LIFT_HANG_FLIPPER_UP[BUTTON] = 9;

	manipulator->CONTROL_LIFT_HANG_FLIPPER_DOWN[STICK] = MANIP;
	manipulator->CONTROL_LIFT_HANG_FLIPPER_DOWN[BUTTON] = 11;

	manipulator->CONTROL_TELEOP_AIM_BOT[STICK] = MANIP;
	manipulator->CONTROL_TELEOP_AIM_BOT[BUTTON] = 12;
	manipulator->CONTROL_TELEOP_AIM_BOT[MODE] = CONTROL_MODE_BTN;
}

void OI::SetUpDrivers() {
	driver->NAME = "RIGHTY";

	driver->CONTROL_MOVEMENT_SLIDER = LEFT;
	driver->DRIVE_TRAIN_INVERTED = false;
	driver->CONTROL_DRIVE_TRAIN_INVERTED[STICK] = LEFT;
	driver->CONTROL_DRIVE_TRAIN_INVERTED[BUTTON] = 1;

	driver->CONTROL_FORWARD[STICK] = RIGHT;
	driver->CONTROL_FORWARD[BUTTON] = 1;

	driver->CONTROL_REVERSE[STICK] = RIGHT;
	driver->CONTROL_REVERSE[BUTTON] = 2;
	driver->CONTROL_REVERSE[MODE] = CONTROL_MODE_BTN;

	driver->CONTROL_TURN_LEFT[STICK] = RIGHT;
	driver->CONTROL_TURN_LEFT[BUTTON] = 3;

	driver->CONTROL_TURN_RIGHT[STICK] = RIGHT;
	driver->CONTROL_TURN_RIGHT[BUTTON] = 4;

	driver->CONTROL_NEUTRAL_MODE[STICK] = LEFT;
	driver->CONTROL_NEUTRAL_MODE[BUTTON] = 2;
}


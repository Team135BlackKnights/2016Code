/*
	LET IT BE KNOWN THAT 'OI' STANDS FOR OPERATOR INTERFACE. THUS IT HAS BEEN DECREED BY THE GREAT EDDIE.
	ALSO NOTE THAT THERE IS ALSO COMMENTING IN THE HEADER FILE
 */
#include <Commands/DriveArm.h>
#include <Commands/DriveLiftHangWinch.h>
#include <Commands/DriveLiftHangFlipper.h>
#include <Subsystems/LiftHangWinch.h>
#include "OI.h"
#include "RobotMap.h"
#include "Commands/DriveJ.h"
#include "CommandBase.h"

#include "Commands/ShootBoulder.h"
#include "Commands/ChangeNeutralMode.h"
#include "Commands/Move.h"
#include "Commands/ArmReset.h"
#include "Commands/ChangeInvertedDriveTrain.h"
#include "Commands/AutomationOfArm.h"
#include "Commands/KickUnstucker.h"
#include "Commands/DriveFlashlight.h"
#include "Commands/OverrideLimitSwitch.h"

// OI::fxn_name means that it is only available to that class. An object of that class must be created in other files
OI::OI()
{
	joysticksArray[LEFT].reset(new Joystick(JOYSTICK_LEFT)); //creates a left joystick object
	joysticksArray[RIGHT].reset(new Joystick(JOYSTICK_RIGHT)); //creates a right joystick object
	joysticksArray[MANIP].reset(new Joystick(JOYSTICK_MANIP));
	joysticksArray[BBOX].reset(new Joystick(JOYSTICK_BBOX)); // creates buttbox object

	for (int i = 0; i < JOYSTICKS; i++) { //assigns values to each button in the array for each controller
		for (int k = 1; k <= MAX_JOYSTICK_BUTTONS; k++)
			buttonsArray[i][k].reset(new JoystickButton(joysticksArray[i].get(), k));
	}

	ResetButtonMapping();

	DefiningDriverVariables();
}

//OI Functions
Joystick* OI::GetStick(int controllerNum)
{
	return joysticksArray[controllerNum].get();
}

float OI::GetStickX(int controllerNum) //Returns controller's x value
{
	return GetStickAxis(controllerNum, Joystick::AxisType::kXAxis);
}

float OI::GetStickY(int controllerNum)
{
	//return -joysticksArray[controllerNum]->GetY();
	return -GetStickAxis(controllerNum, Joystick::AxisType::kYAxis);
}

float OI::GetStickTwist(int controllerNum)
{
	return GetStickAxis(controllerNum, Joystick::AxisType::kTwistAxis);
}

float OI::GetStickSlider(int controllerNum)
{
	return 1 - joysticksArray[controllerNum]->GetThrottle(); //Gets throttle value and reverses it because the throttle is backwards
}

bool OI::GetButton(int controllerNum, int buttonNum) //Gets whether or not a button is pressed or not
{
	return buttonsArray[controllerNum][buttonNum]->Get();
}

int OI::GetPOV(int stick)
{
	return joysticksArray[stick]->GetPOV();
}

bool OI::IsPOV(int stick, int data)
{
	int value = joysticksArray[stick]->GetPOV();
	if (value < 0) return false;

	int offset = (value / 360.0f) * POV_COUNT;
	bool pressed = ((data >> offset) & 1);
	return pressed;
}

bool OI::IsPressed(int data[3])
{
	if (data[MODE] == CONTROL_MODE_POV)
		return IsPOV(data[STICK], data[BUTTON]);
	else if (data[MODE] == CONTROL_MODE_BTN)
		return GetButton(data[STICK], data[BUTTON]);
	else
		return false;
}

float OI::GetStickAxis(int controllerNum, Joystick::AxisType axis)
{
	float value = joysticksArray[controllerNum]->GetAxis(axis);
	//if (abs(value) > DEAD_BAND)
		return value;

	//return 0;
}

/*void OI::UpdateDriver(Driver* driver, bool updateButtons)
{
	this->driver = driver;
	std::cout << this->NAME;
	if (updateButtons)
		ResetButtonMapping();
}

void OI::UpdateManipulator(Manipulator* manipulator, bool updateButtons)
{
	this->manipulator = manipulator;
	std::cout << this->NAME;
	if (updateButtons)
		ResetButtonMapping();
} */

JoystickButton* OI::GetAButton(int data[2]) {
	return buttonsArray[data[STICK]][data[BUTTON]].get();
}

void OI::ResetButtonMapping()
{
	joysticksArray[LEFT].reset(new Joystick(JOYSTICK_LEFT)); //creates a left joystick object
	joysticksArray[RIGHT].reset(new Joystick(JOYSTICK_RIGHT)); //creates a right joystick object
	joysticksArray[MANIP].reset(new Joystick(JOYSTICK_MANIP));
	joysticksArray[BBOX].reset(new Joystick(JOYSTICK_BBOX)); // creates buttbox object


	for (int i = 0; i < JOYSTICKS; i++) { //assigns values to each button in the array for each controller
		for (int k = 1; k <= MAX_JOYSTICK_BUTTONS; k++) {
			buttonsArray[i][k].release();
			delete buttonsArray[i][k].get();
			buttonsArray[i][k].reset(new JoystickButton(joysticksArray[i].get(), k));
		}
	}

	//buttonsArray[CONTROL_SHOOT[STICK]][CONTROL_SHOOT[BUTTON]]->WhenPressed(new AimBot());
	//buttonsArray[CONTROL_ARM_RESET[STICK]][CONTROL_ARM_RESET[BUTTON]]->WhenPressed(new ArmReset());

	buttonsArray[CONTROL_LIFT_HANG_UP[STICK]][CONTROL_LIFT_HANG_UP[BUTTON]]->WhileHeld(new DriveLiftHangWinch(LiftHangWinch::WINCH_UP));
	buttonsArray[CONTROL_LIFT_HANG_DOWN[STICK]][CONTROL_LIFT_HANG_DOWN[BUTTON]]->WhileHeld(new DriveLiftHangWinch(LiftHangWinch::WINCH_DOWN));

	buttonsArray[CONTROL_LIFT_HANG_FLIPPER_UP[STICK]][CONTROL_LIFT_HANG_FLIPPER_UP[BUTTON]]->WhileHeld(new DriveLiftHangFlipper(LiftHangFlipFlip::FLIPPER_UP));
	buttonsArray[CONTROL_LIFT_HANG_FLIPPER_DOWN[STICK]][CONTROL_LIFT_HANG_FLIPPER_DOWN[BUTTON]]->WhileHeld(new DriveLiftHangFlipper(LiftHangFlipFlip::FLIPPER_DOWN));

	buttonsArray[CONTROL_FORWARD[STICK]][CONTROL_FORWARD[BUTTON]]->WhileHeld(new Move(Move::FORWARD * STRAIGHT_MOVEMENT_MULTIPLIER));
	buttonsArray[CONTROL_REVERSE[STICK]][CONTROL_REVERSE[BUTTON]]->WhileHeld(new Move(Move::REVERSE * STRAIGHT_MOVEMENT_MULTIPLIER));

	buttonsArray[CONTROL_TURN_LEFT[STICK]][CONTROL_TURN_LEFT[BUTTON]]->WhileHeld(new Move(Move::REVERSE * TURN_MOVEMENT_MULTIPLIER, Move::FORWARD * TURN_MOVEMENT_MULTIPLIER));
	buttonsArray[CONTROL_TURN_RIGHT[STICK]][CONTROL_TURN_RIGHT[BUTTON]]->WhileHeld(new Move(Move::FORWARD * TURN_MOVEMENT_MULTIPLIER, Move::REVERSE * TURN_MOVEMENT_MULTIPLIER));

	buttonsArray[CONTROL_NEUTRAL_MODE[STICK]][CONTROL_NEUTRAL_MODE[BUTTON]]->WhenPressed(new ChangeNeutralMode(DriveTrain::COAST));
	buttonsArray[CONTROL_NEUTRAL_MODE[STICK]][CONTROL_NEUTRAL_MODE[BUTTON]]->WhenReleased(new ChangeNeutralMode(DriveTrain::BRAKE));

	buttonsArray[CONTROL_DRIVE_TRAIN_INVERTED[STICK]][CONTROL_DRIVE_TRAIN_INVERTED[BUTTON]]->WhenPressed(new ChangeInvertedDriveTrain(true));
	buttonsArray[CONTROL_DRIVE_TRAIN_INVERTED[STICK]][CONTROL_DRIVE_TRAIN_INVERTED[BUTTON]]->WhenReleased(new ChangeInvertedDriveTrain(false));

	/*
	buttonsArray[MANIP][4]->WhenPressed(new AutomationOfArm(35.0D));
	buttonsArray[MANIP][6]->WhenPressed(new AutomationOfArm(40.0D));
	buttonsArray[MANIP][5]->WhenPressed(new AutomationOfArm(58.0D));
	*/
	buttonsArray[MANIP][12]->WhenPressed(new OverrideLimitSwitch());
	//buttonsArray[MANIP][4]->ToggleWhenPressed(new AutomationOfArm(54.7D));
	//buttonsArray[MANIP][6]->WhenPressed(new AutomationOfArm(Arm::ARM_UP_POSITION / Arm::ENCODER_MULTIPLYING_CONSTANT));
	//buttonsArray[MANIP][4]->ToggleWhenPressed(new AutomationOfArm(33.0D));
	//buttonsArray[MANIP][6]->ToggleWhenPressed(new AutomationOfArm(38.0D));
	//buttonsArray[MANIP][5]->ToggleWhenPressed(new AutomationOfArm(54.0D));
	//buttonsArray[MANIP][12]->ToggleWhenPressed(new TeleOpAimBot());
	//GetAButton(CONTROL_TELEOP_AIM_BOT)->WhileHeld(new TeleOpAimBot());
	//buttonsArray[MANIP][8]->ToggleWhenPressed(new AutomationOfArm());

	//buttonsArray[MANIP][12]->WhileHeld(new KickUnstucker());
	buttonsArray[MANIP][7]->WhenPressed(new DriveFlashlight(true));
	DriveFlashlight* turnOff = new DriveFlashlight(false);
	turnOff->Start();
	buttonsArray[MANIP][8]->WhenPressed(turnOff);
}

void OI::DefiningDriverVariables() {
	CONTROL_SHOOT[STICK] = LEFT;
	CONTROL_SHOOT[BUTTON] = 1;

	CONTROL_SHOOTER_IN[STICK] = MANIP;
	CONTROL_SHOOTER_IN[BUTTON] = 2;

	CONTROL_SHOOTER_OUT[STICK] = MANIP;
	CONTROL_SHOOTER_OUT[BUTTON] = 1;

	CONTROL_SHOOTER_INTAKE_OVERRIDE[STICK] = LEFT;
	CONTROL_SHOOTER_INTAKE_OVERRIDE[BUTTON] = 2;

	CONTROL_SHOOTER_KICKER_KICK[STICK] = MANIP;
	CONTROL_SHOOTER_KICKER_KICK[BUTTON] = 3;
	CONTROL_SHOOTER_KICKER_KICK[MODE] = CONTROL_MODE_BTN;

	CONTROL_ARM_RESET[STICK] = LEFT;
	CONTROL_ARM_RESET[BUTTON] = 2;

	CONTROL_ARM_STOP[STICK] = MANIP;
	CONTROL_ARM_STOP[BUTTON] = 0b11111111;
	CONTROL_ARM_STOP[MODE] = CONTROL_MODE_POV;

	CONTROL_ARM_STICK = MANIP;
	CONTROL_ARM_INVERTED = true;
	CONTROL_ARM_AXIS = Joystick::AxisType::kYAxis;

	CONTROL_ARM_REMOVE_SOFT_STOP[STICK] = RIGHT;
	CONTROL_ARM_REMOVE_SOFT_STOP[BUTTON] = 11;

	CONTROL_LIFT_HANG_UP[STICK] = MANIP;
	CONTROL_LIFT_HANG_UP[BUTTON] = 10;

	CONTROL_LIFT_HANG_DOWN[STICK] = RIGHT;
	CONTROL_LIFT_HANG_DOWN[BUTTON] = 7;

	CONTROL_LIFT_HANG_FLIPPER_UP[STICK] = MANIP;
	CONTROL_LIFT_HANG_FLIPPER_UP[BUTTON] = 9;

	CONTROL_LIFT_HANG_FLIPPER_DOWN[STICK] = MANIP;
	CONTROL_LIFT_HANG_FLIPPER_DOWN[BUTTON] = 11;

	CONTROL_TELEOP_AIM_BOT[STICK] = MANIP;
	CONTROL_TELEOP_AIM_BOT[BUTTON] = 12;
	CONTROL_TELEOP_AIM_BOT[MODE] = CONTROL_MODE_BTN;

	CONTROL_MOVEMENT_SLIDER = LEFT;
	DRIVE_TRAIN_INVERTED = false;
	CONTROL_DRIVE_TRAIN_INVERTED[STICK] = LEFT;
	CONTROL_DRIVE_TRAIN_INVERTED[BUTTON] = 1;

	CONTROL_FORWARD[STICK] = RIGHT;
	CONTROL_FORWARD[BUTTON] = 1;

	CONTROL_REVERSE[STICK] = RIGHT;
	CONTROL_REVERSE[BUTTON] = 2;
	CONTROL_REVERSE[MODE] = CONTROL_MODE_BTN;

	CONTROL_TURN_LEFT[STICK] = RIGHT;
	CONTROL_TURN_LEFT[BUTTON] = 3;

	CONTROL_TURN_RIGHT[STICK] = RIGHT;
	CONTROL_TURN_RIGHT[BUTTON] = 4;

	CONTROL_NEUTRAL_MODE[STICK] = LEFT;
	CONTROL_NEUTRAL_MODE[BUTTON] = 2;
}

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
#include "Commands/AimBot.h"
#include "Commands/ArmReset.h"
#include "Commands/ChangeDriver.h"
#include "Commands/ChangeInvertedDriveTrain.h"
#include "Commands/AutomationOfArm.h"
#include "Commands/KickUnstucker.h"
#include "Commands/TeleOpAimBot.h"
#include "Commands/DriveFlashlight.h"
#include "Commands/GetSonarDistances.h"
#include "Commands/SerialCommunicationTesting.h"

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

	driver = new Driver();
	manipulator = new Manipulator();

	SetUpManipulators();
	SetUpDrivers();

	ResetButtonMapping();
	resetArm = new ArmResetOnDetonatorButton();
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

void OI::UpdateDriver(Driver* driver, bool updateButtons)
{
	this->driver = driver;
	std::cout << this->driver->NAME;
	if (updateButtons)
		ResetButtonMapping();
}

void OI::UpdateManipulator(Manipulator* manipulator, bool updateButtons)
{
	this->manipulator = manipulator;
	std::cout << this->manipulator->NAME;
	if (updateButtons)
		ResetButtonMapping();
}

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

	buttonsArray[manipulator->CONTROL_SHOOT[STICK]][manipulator->CONTROL_SHOOT[BUTTON]]->ToggleWhenPressed(new SerialCommunicationTesting());

	//buttonsArray[manipulator->CONTROL_SHOOT[STICK]][manipulator->CONTROL_SHOOT[BUTTON]]->WhenPressed(new AimBot());
	//buttonsArray[manipulator->CONTROL_ARM_RESET[STICK]][manipulator->CONTROL_ARM_RESET[BUTTON]]->WhenPressed(new ArmReset());

	buttonsArray[manipulator->CONTROL_LIFT_HANG_UP[STICK]][manipulator->CONTROL_LIFT_HANG_UP[BUTTON]]->WhileHeld(new DriveLiftHangWinch(LiftHangWinch::WINCH_UP));
	buttonsArray[manipulator->CONTROL_LIFT_HANG_DOWN[STICK]][manipulator->CONTROL_LIFT_HANG_DOWN[BUTTON]]->WhileHeld(new DriveLiftHangWinch(LiftHangWinch::WINCH_DOWN));

	buttonsArray[manipulator->CONTROL_LIFT_HANG_FLIPPER_UP[STICK]][manipulator->CONTROL_LIFT_HANG_FLIPPER_UP[BUTTON]]->WhileHeld(new DriveLiftHangFlipper(LiftHangFlipFlip::FLIPPER_UP));
	buttonsArray[manipulator->CONTROL_LIFT_HANG_FLIPPER_DOWN[STICK]][manipulator->CONTROL_LIFT_HANG_FLIPPER_DOWN[BUTTON]]->WhileHeld(new DriveLiftHangFlipper(LiftHangFlipFlip::FLIPPER_DOWN));

	buttonsArray[driver->CONTROL_FORWARD[STICK]][driver->CONTROL_FORWARD[BUTTON]]->WhileHeld(new Move(Move::FORWARD * STRAIGHT_MOVEMENT_MULTIPLIER));
	buttonsArray[driver->CONTROL_REVERSE[STICK]][driver->CONTROL_REVERSE[BUTTON]]->WhileHeld(new Move(Move::REVERSE * STRAIGHT_MOVEMENT_MULTIPLIER));

	buttonsArray[driver->CONTROL_TURN_LEFT[STICK]][driver->CONTROL_TURN_LEFT[BUTTON]]->WhileHeld(new Move(Move::REVERSE * TURN_MOVEMENT_MULTIPLIER, Move::FORWARD * TURN_MOVEMENT_MULTIPLIER));
	buttonsArray[driver->CONTROL_TURN_RIGHT[STICK]][driver->CONTROL_TURN_RIGHT[BUTTON]]->WhileHeld(new Move(Move::FORWARD * TURN_MOVEMENT_MULTIPLIER, Move::REVERSE * TURN_MOVEMENT_MULTIPLIER));

	buttonsArray[driver->CONTROL_NEUTRAL_MODE[STICK]][driver->CONTROL_NEUTRAL_MODE[BUTTON]]->WhenPressed(new ChangeNeutralMode(DriveTrain::COAST));
	buttonsArray[driver->CONTROL_NEUTRAL_MODE[STICK]][driver->CONTROL_NEUTRAL_MODE[BUTTON]]->WhenReleased(new ChangeNeutralMode(DriveTrain::BRAKE));

	buttonsArray[driver->CONTROL_DRIVE_TRAIN_INVERTED[STICK]][driver->CONTROL_DRIVE_TRAIN_INVERTED[BUTTON]]->WhenPressed(new ChangeInvertedDriveTrain(true));
	buttonsArray[driver->CONTROL_DRIVE_TRAIN_INVERTED[STICK]][driver->CONTROL_DRIVE_TRAIN_INVERTED[BUTTON]]->WhenReleased(new ChangeInvertedDriveTrain(false));

	/*
	buttonsArray[MANIP][4]->WhenPressed(new AutomationOfArm(35.0D));
	buttonsArray[MANIP][6]->WhenPressed(new AutomationOfArm(40.0D));
	buttonsArray[MANIP][5]->WhenPressed(new AutomationOfArm(58.0D));
	*/
	buttonsArray[MANIP][4]->ToggleWhenPressed(new AutomationOfArm(33.0D));
	buttonsArray[MANIP][6]->ToggleWhenPressed(new AutomationOfArm(38.0D));
	buttonsArray[MANIP][5]->ToggleWhenPressed(new AutomationOfArm(54.0D));
	GetAButton(manipulator->CONTROL_TELEOP_AIM_BOT)->WhileHeld(new TeleOpAimBot());
	//buttonsArray[MANIP][8]->ToggleWhenPressed(new AutomationOfArm());

	//buttonsArray[MANIP][12]->WhileHeld(new KickUnstucker());
	buttonsArray[MANIP][7]->WhenPressed(new DriveFlashlight());
}

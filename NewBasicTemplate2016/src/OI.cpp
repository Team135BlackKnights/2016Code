#include <Commands/DriveArm.h>
#include "OI.h"
#include "RobotMap.h"
#include "Commands/DriveJ.h"
#include "CommandBase.h"

#include "Commands/RunningOverDefense.h"
#include "Commands/DriveDistance.h"

#include "Commands/ShootBoulder.h"
#include "Commands/DriveLiftHang.h"
#include "Commands/ChangeNeutralMode.h"
#include "Commands/Move.h"
#include "Subsystems/LiftHang.h"
#include "Commands/AimBot.h"
#include "Commands/ArmReset.h"
#include "Commands/ChangeDriver.h"

// OI::fxn_name means that it is only available to that class. An object of that class must be created in other files
OI::OI()
{
	joysticksArray[LEFT].reset(new Joystick(JOYSTICK_LEFT)); //creates a left joystick object
	joysticksArray[RIGHT].reset(new Joystick(JOYSTICK_RIGHT)); //creates a right joystick object
	joysticksArray[MANIP].reset(new Joystick(JOYSTICK_MANIP));
	joysticksArray[BBOX].reset(new Joystick(JOYSTICK_BBOX)); // creates buttbox object


	lefty = new Driver();
	righty = new Driver();
	chris = new Manipulator();
	sam = new Manipulator();
	brandon = new Manipulator();

	SetUpManipulators();
	SetUpDrivers();

	driver = lefty;
	manipulator = sam;

	resetArm = new ArmResetOnDetonatorButton();
	//resetArm->WhenActive(new ArmReset());
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

void OI::UpdateDriver(Driver* driver)
{
	this->driver = driver;
	std::cout << this->driver->NAME;
	ResetButtonMapping();
}

void OI::UpdateManipulator(Manipulator* manipulator)
{
	this->manipulator = manipulator;
	std::cout << this->manipulator->NAME;
	ResetButtonMapping();
}

void OI::ResetButtonMapping()
{
	for (int i = 0; i < JOYSTICKS; i++) { //assigns values to each button in the array for each controller
		for (int k = 1; k <= MAX_JOYSTICK_BUTTONS; k++) {
			buttonsArray[i][k].release();
			//delete buttonsArray[i][k].get();
			buttonsArray[i][k].reset(new JoystickButton(joysticksArray[i].get(), k));
		}
	}

	buttonsArray[manipulator->CONTROL_SHOOT[STICK]][manipulator->CONTROL_SHOOT[BUTTON]]->WhenPressed(new AimBot());
	//buttonsArray[manipulator->CONTROL_ARM_RESET[STICK]][manipulator->CONTROL_ARM_RESET[BUTTON]]->WhenPressed(new ArmReset());

	buttonsArray[driver->CONTROL_FORWARD[STICK]][driver->CONTROL_FORWARD[BUTTON]]->WhileHeld(new Move(Move::FORWARD, Move::FORWARD));
	if (driver->CONTROL_REVERSE[MODE] == CONTROL_MODE_BTN)
		buttonsArray[driver->CONTROL_REVERSE[STICK]][driver->CONTROL_REVERSE[BUTTON]]->WhileHeld(new Move(Move::REVERSE, Move::REVERSE));
	else {
		//NEEDS IMPLEMENTED
	}

	buttonsArray[driver->CONTROL_TURN_LEFT[STICK]][driver->CONTROL_TURN_LEFT[BUTTON]]->WhileHeld(new Move(Move::REVERSE, Move::FORWARD));
	buttonsArray[driver->CONTROL_TURN_RIGHT[STICK]][driver->CONTROL_TURN_RIGHT[BUTTON]]->WhileHeld(new Move(Move::FORWARD, Move::REVERSE));

	buttonsArray[driver->CONTROL_NEUTRAL_MODE[STICK]][driver->CONTROL_NEUTRAL_MODE[BUTTON]]->WhenPressed(new ChangeNeutralMode(DriveTrain::COAST));
	buttonsArray[driver->CONTROL_NEUTRAL_MODE[STICK]][driver->CONTROL_NEUTRAL_MODE[BUTTON]]->WhenReleased(new ChangeNeutralMode(DriveTrain::BRAKE));
}

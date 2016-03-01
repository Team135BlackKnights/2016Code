/*
	LET IT BE KNOWN THAT 'OI' STANDS FOR OPERATOR INTERFACE. THUS IT HAS BEEN DECREED BY THE GREAT EDDIE.
	ALSO NOTE THAT THERE IS ALSO COMMENTING IN THE HEADER FILE
 */
#include <Commands/DriveArm.h>
#include "OI.h"
#include "RobotMap.h"
#include "Commands/DriveJ.h"
#include "CommandBase.h"

#include "Commands/ShootBoulder.h"
#include "Commands/DriveLiftHang.h"
#include "Commands/ChangeNeutralMode.h"
#include "Commands/Move.h"
#include "Subsystems/LiftHang.h"
#include "Commands/AimBot.h"
#include "Commands/ArmReset.h"
#include "Commands/ChangeDriver.h"
//#include "Commands/ChangeManipulator.h"
//#include "Triggers/ArmResetOnButton.h"

// OI::fxn_name means that it is only available to that class. An object of that class must be created in other files
OI::OI()
{
	joysticksArray[LEFT].reset(new Joystick(JOYSTICK_LEFT)); //creates a left joystick object
	joysticksArray[RIGHT].reset(new Joystick(JOYSTICK_RIGHT)); //creates a right joystick object
	joysticksArray[MANIP].reset(new Joystick(JOYSTICK_MANIP));
	joysticksArray[BBOX].reset(new Joystick(JOYSTICK_BBOX)); // creates buttbox object

	for (int i = 0; i < JOYSTICKS; i++) //assigns values to each button in the array for each controller
			for (int k = 1; k <= MAX_JOYSTICK_BUTTONS; k++)
				buttonsArray[i][k].reset(new JoystickButton(joysticksArray[i].get(), k));

	lefty = new Driver();
	righty = new Driver();
	chris = new Manipulator();
	sam = new Manipulator();

	SetUpManipulators();
	SetUpDrivers();

	driver = new Driver(*lefty);
	manipulator = new Manipulator(*sam);

	/*
	for (int i = 0; i < 8; i++) {
		(new POV(0, 45 * i))->WhileActive(new Move(CONTROL_POV[i][0], CONTROL_POV[i][1]));
	}
	*/
	//resetArm = new ArmResetOnButton();
	//resetArm->WhenActive(new ArmReset());

	/*
	buttonsArray[manipulator->CONTROL_SHOOT[STICK]][manipulator->CONTROL_SHOOT[BUTTON]]->WhenPressed(new AimBot());
	buttonsArray[manipulator->CONTROL_ARM_RESET[STICK]][manipulator->CONTROL_ARM_RESET[BUTTON]]->WhenPressed(new ArmReset());

	buttonsArray[driver->CONTROL_FORWARD[STICK]][driver->CONTROL_FORWARD[BUTTON]]->WhileHeld(new Move(Move::FORWARD, Move::FORWARD));
	buttonsArray[driver->CONTROL_REVERSE[STICK]][driver->CONTROL_REVERSE[BUTTON]]->WhileHeld(new Move(Move::REVERSE, Move::REVERSE));
	buttonsArray[driver->CONTROL_TURN_LEFT[STICK]][driver->CONTROL_TURN_LEFT[BUTTON]]->WhileHeld(new Move(Move::REVERSE, Move::FORWARD));
	buttonsArray[driver->CONTROL_TURN_RIGHT[STICK]][driver->CONTROL_TURN_RIGHT[BUTTON]]->WhileHeld(new Move(Move::FORWARD, Move::REVERSE));

	buttonsArray[driver->CONTROL_NEUTRAL_MODE[STICK]][driver->CONTROL_NEUTRAL_MODE[BUTTON]]->WhenPressed(new ChangeNeutralMode(DriveTrain::COAST));
	buttonsArray[driver->CONTROL_NEUTRAL_MODE[STICK]][driver->CONTROL_NEUTRAL_MODE[BUTTON]]->WhenReleased(new ChangeNeutralMode(DriveTrain::BRAKE));
	*/
}

//OI Functions
Joystick* OI::GetStick(int controllerNum)
{
	return joysticksArray[controllerNum].get();
}

float OI::GetStickX(int controllerNum) //Returns controller's x value
{
	float value = joysticksArray[controllerNum]->GetX(); //Gets x value from joystick
	//makes value equal to the output of GetX() when the parameter is joysticksArray[controllerNum]

	//if (abs(value) > DEAD_ZONE)
		return value; //returns 0 if controllers are within the deadzone
	//return value;
}

float OI::GetStickY(int controllerNum)
{
	float value = -joysticksArray[controllerNum]->GetY(); //Gets y value from joystick

	//if (abs(value) > DEAD_ZONE)
		return value; //returns 0 if controllers are within the deadzone
	//return value;
}

float OI::GetStickTwist(int controllerNum)
{
	float value = joysticksArray[controllerNum]->GetTwist(); //Gets twist value from joystick
	return value;
}

float OI::GetStickAxis(int controllerNum, Joystick::AxisType axis) {
	return joysticksArray[controllerNum]->GetAxis(axis);
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

float OI::GetAxis(int stick, Joystick::AxisType axis)
{
	return joysticksArray[stick]->GetAxis(axis);
}

void OI::UpdateDriver(Driver* driver)
{
	this->driver = driver;
}

void OI::UpdateManipulator(Manipulator* manipulator)
{
	this->manipulator = manipulator;
	std::cout << this->manipulator->NAME;
}

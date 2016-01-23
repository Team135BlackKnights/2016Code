#include "JoystickTesting.h"

JoystickTesting::JoystickTesting()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain.get());
}

// Called just before this Command runs the first time
void JoystickTesting::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void JoystickTesting::Execute()
{
	if (oi->GetButton[JOYSTICK_LEFT][JOYSTICK_BUTTON_TESTER] == true) {
		joystickX = oi->GetStickX(JOYSTICK_LEFT);
		joystickY = oi->GetStickY(JOYSTICK_LEFT);

		SmartDashboard::PutNumber("JoystickX Value:", joystickX);
		SmartDashboard::PutNumber("JoystickY Value", joystickY);

		driveTrain->LogPIDValues(joystickX, joystickY);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool JoystickTesting::IsFinished()
{
	if (oi->GetButton[JOYSTICK_LEFT][JOYSTICK_BUTTON_TESTER] == false) {
		return true;
	}
	else {
		return false;

	}
}

// Called once after isFinished returns true
void JoystickTesting::End()
{
	driveTrain->CloseLogFile();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void JoystickTesting::Interrupted()
{
	driveTrain->LogPIDValues(000, 000);

}

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
		joystickX = oi->GetStickX(JOYSTICK_LEFT);
		joystickY = oi->GetStickY(JOYSTICK_LEFT);

		SmartDashboard::PutNumber("JoystickX Value:", joystickX);
		SmartDashboard::PutNumber("JoystickY Value", joystickY);

		//logData->WriteTwoDoubles(joystickX, joystickY, joystickFileName);
}

// Make this return true when this Command no longer needs to run execute()
bool JoystickTesting::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void JoystickTesting::End()
{
	//logData->CloseFile();
}


// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void JoystickTesting::Interrupted()
{
	//logData->WriteTwoDoubles(000, 000, joystickFileName);
	//logData->CloseFile();
}

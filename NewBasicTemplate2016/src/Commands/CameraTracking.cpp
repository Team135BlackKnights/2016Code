
#include <Commands/CameraTracking.h>
#include <OI.h>
#include <Subsystems/AxisCam.h>
#include <cstdbool>
#include <iostream>
#include <memory>
#include "../RobotMap.h"


CameraTracking::CameraTracking()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(cam.get());
}

// Called just before this Command runs the first time
void CameraTracking::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void CameraTracking::Execute()
{
	cam->GetCameraValues();

	cam->UpdateServo();

}

// Make this return true when this Command no longer needs to run execute()
bool CameraTracking::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void CameraTracking::End()
{
	cam->TogglePID(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CameraTracking::Interrupted()
{
	this->End();
}

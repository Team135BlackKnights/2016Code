#include "USBCam.h"
#include "../RobotMap.h"

USBCam::USBCam() :
		Subsystem("ExampleSubsystem")
{
	CameraServer::GetInstance()->SetQuality(50);
	//Start the automatic capture to dashboard
	CameraServer::GetInstance()->StartAutomaticCapture(CAMERA_NAME);
}

void USBCam::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

#include "USBCam.h"
#include "../RobotMap.h"

USBCam::USBCam() :
		Subsystem("ExampleSubsystem")
{

}

void USBCam::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	CameraServer::GetInstance()->SetQuality(50); //set the cam quality of jpeg to be around 50 (out of 100)

	CameraServer::GetInstance()->StartAutomaticCapture(CAMERA_NAME);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

#include "CameraUSB.h"
#include "../RobotMap.h"
#include "Commands/CameraStream.h"

CameraUSB::CameraUSB() :
		Subsystem("ExampleSubsystem")
{
	/*camera.reset(new USBCamera("cam2", true));
	camera->OpenCamera();
	camera->SetExposureAuto();
	camera->StartCapture();
	imageFrame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
	*///CameraServer::GetInstance()->StartAutomaticCapture(camera);
}

void CameraUSB::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	//SetDefaultCommand(new CameraStream());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

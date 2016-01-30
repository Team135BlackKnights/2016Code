#include "USBCam.h"
#include "../RobotMap.h"
#include "wpilib.h"

USBCam::USBCam() :
		Subsystem("ExampleSubsystem")
{
	//create le image
	frame.reset(imaqCreateImage(IMAQ_IMAGE_RGB,0));
	//cam name
	/*imaqError = IMAQdxOpenCamera("cam0", IMAQdxCameraControlModeController, &session);
	if(imaqError != IMAQdxErrorSuccess) {
		DriverStation::ReportError("IMAQdxOpenCamera error: " + std::to_string((long)imaqError) + "\n");
	}*/

}

void USBCam::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

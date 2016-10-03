#include "CameraUSB.h"
#include "../RobotMap.h"
#include "Commands/CameraStream.h"
#include <nivision.h>

CameraUSB::CameraUSB() :
		Subsystem("ExampleSubsystem")
{
}



void CameraUSB::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	//SetDefaultCommand(new CameraStream());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

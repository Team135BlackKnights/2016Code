#ifndef USBCam_H
#define USBCam_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class USBCam: public Subsystem
{
private:
	const char* CAMERA_NAME = "cam2";
public:
	USBCam();
	void InitDefaultCommand();
};

#endif

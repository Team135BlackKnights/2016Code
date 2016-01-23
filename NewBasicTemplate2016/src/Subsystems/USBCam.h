#ifndef USBCam_H
#define USBCam_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class USBCam: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	const char* CAMERA_NAME = "cam2";
public:
	USBCam();
	void InitDefaultCommand();
};

#endif

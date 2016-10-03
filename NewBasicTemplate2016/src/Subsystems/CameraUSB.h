#ifndef CameraUSB_H
#define CameraUSB_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class CameraUSB: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	CameraUSB();
	void InitDefaultCommand();
};

#endif

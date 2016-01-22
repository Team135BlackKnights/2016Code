#ifndef USBCam_H
#define USBCam_H

#include <Commands/Subsystem.h>
#include <networktables/NetworkTable.h>
#include <memory>
#include "WPILib.h"
#include <unistd.h>

class USBCam: public Subsystem
{
private:
	const char* CAMERA_NAME = "cam2";
	std::unique_ptr<NetworkTable> visionTable;
	double targetX = 0.0;
	double targetY = 0.0;
	double targetArea = -1.0;
	const int XWIDTH = 360;
	const int YWIDTH = 240;
public:
	USBCam();
	void InitDefaultCommand();
	void findBiggest();
	double xDistanceToCenter(double x);
	double yDistanceToCenter(double y);
	double percentArea(double area);
};

#endif

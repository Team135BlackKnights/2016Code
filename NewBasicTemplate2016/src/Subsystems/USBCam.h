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
	const int X_IMAGE_RES = 320;
	const int Y_IMAGE_RES = 240;
	const int X_WIDTH_GOAL = 20; //in inches
	const int Y_HEIGHT_GOAL = 14; //inches
	int PIXEL_WIDTH; //find this
	const double AXIS_VANGLE = 67;
	double x;
	double y;
	double width;
	double height;
public:
	USBCam();
	void InitDefaultCommand();
	void findBiggest();
	double xDistanceToCenter(double x);
	double yDistanceToCenter(double y);
	double percentArea(double area);
	double getX();
	double getY();
	double getWidth();
	double getHeight();
	double distanceToBlob(double x, double y, double width, double height);
};

#endif

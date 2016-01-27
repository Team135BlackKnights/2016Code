
#ifndef AxisCam_H
#define AxisCam_H

#include <Commands/Subsystem.h>
#include <networktables/NetworkTable.h>
#include "../CommandBase.h"
#include <memory>
#include "WPILib.h"
#include <unistd.h>

class AxisCam: public Subsystem
{
private:
	const char* CAMERA_NAME = "cam2";
	std::shared_ptr<NetworkTable> visionTable;
	double targetX = 0.0;
	double targetY = 0.0;
	double targetArea = -1.0;
	const int X_IMAGE_RES = 360;
	const int Y_IMAGE_RES = 480;
	const int X_WIDTH_GOAL = 20; //in inches
	const int Y_HEIGHT_GOAL = 14; //inches
	const double AXIS_VANGLE = 67;
	double x;
	double y;
	double width;
	double height;
	std::unique_ptr<Servo> yServo;
	std::unique_ptr<Servo> xServo;
public:
	AxisCam();
	void InitDefaultCommand();
	void GetCameraValues();
	double xDistanceToCenter();
	double yDistanceToCenter();
	double percentArea(double area);
	double getX();
	double getY();
	double getWidth();
	double getHeight();
	double distanceToBlob(double pixel_width);
	void setServoY();
	void setServoX();
};

#endif

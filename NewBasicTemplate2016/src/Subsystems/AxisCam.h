#ifndef AxisCam_H
#define AxisCam_H

#include <Commands/Subsystem.h>
#include <networktables/NetworkTable.h>
#include <memory>
#include "WPILib.h"
#include <unistd.h>
#include "RobotMap.h"

//#include "Servo.h"

class AxisCam: public Subsystem
{
private:
	const char* CAMERA_NAME = "cam2";
	std::shared_ptr<NetworkTable> visionTable;
	double targetX = 0.0;
	double targetY = 0.0;
	double targetArea = -1.0;
	const float X_IMAGE_RES = 320;
	const float Y_IMAGE_RES = 240;
	const float X_WIDTH_GOAL = 20.0/12.0; //in feet
	const float Y_HEIGHT_GOAL = 1.0; //feet
	const double AXIS_VANGLE = 45;//67;
	float x;
	float y;
	float width;
	float height;

public:
	AxisCam();
	void InitDefaultCommand();
	void GetCameraValues();
	float xDistanceToCenter();
	float yDistanceToCenter();
	float percentArea(double area);
	float getX();
	float getY();
	float getWidth();
	float getHeight();
	float distanceToBlob(double pixel_width);
	void setServoY();
	void setServoX();
	void SetServo(Servo* servo, float value);
	void setServoX(float value);
	void SetServoY(float value);
	float angleToBlob(double dist);
	std::unique_ptr<Servo> yServo;
	std::unique_ptr<Servo> xServo;
};

#endif

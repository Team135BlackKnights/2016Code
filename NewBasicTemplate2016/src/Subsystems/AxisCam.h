#ifndef AxisCam_H
#define AxisCam_H

#include <Commands/Subsystem.h>
#include <networktables/NetworkTable.h>
#include <memory>
#include "WPILib.h"
#include <unistd.h>
#include "RobotMap.h"
#include <PIDController.h>
#include "Subsystems/ServoPID.h"




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
	ServoPID* pidServoX;
	PIDController* pidX;
	const int CAMERA_CENTER_X = X_IMAGE_RES / 2;
	const int CAMERA_CENTER_Y = Y_IMAGE_RES / 2;
	const int PAN_PROPORTIONAL_GAIN = 400;
	const int PAN_DERIVATIVE_GAIN = 300;
	const int TILT_PROPORTIONAL_GAIN = 500;
	const int TILT_DERIVATIVE_GAIN = 400;
	const float X_WIDTH_GOAL = 20.0/12.0; //in feet
	const float Y_HEIGHT_GOAL = 1.0; //feet
	const double AXIS_VANGLE = 45;//67;
	float x;
	float y;
	float width;
	float height;
	float searchSize = 0.05f;

public:
	AxisCam();
	void InitDefaultCommand();
	void GetCameraValues();
	void InitGimbals();
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
	float GetMotorValues();
	float GetXMultiplier(float offset);
	float GetYMultiplier(float offset);
	void UpdateServo();
	void TogglePID(bool);
	void Scan(Servo* servo);
	//std::unique_ptr<Servo> yServo;
	std::unique_ptr<Servo> xServo;
};

#endif

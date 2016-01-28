#include <RobotMap.h>
#include <math.h>
#include <Subsystems/AxisCam.h>
#include "../Commands/CameraTracking.h"

AxisCam::AxisCam():
		Subsystem("AxisCam")
{
	//grip.reset(NetworkTable::GetTable("grip").get());
	visionTable = NetworkTable::GetTable("SmartDashboard");
	height = 0;
	width = 0;
	x = 0;
	y = 0;
	yServo.reset(new Servo(SERVO_PORT_Y));
	xServo.reset(new Servo(SERVO_PORT_X));
}

void AxisCam::InitDefaultCommand()
{
	//set the cam quality of jpeg to be around 50 (out of 100)
	//CameraServer::GetInstance()->SetQuality(50);
	//Start the automatic capture to dashboard
	//CameraServer::GetInstance()->StartAutomaticCapture(CAMERA_NAME);
	SetDefaultCommand(new CameraTracking());
}


void AxisCam::GetCameraValues()
{
	//visionTable->
	auto xys = visionTable->GetNumberArray("BLOB_XY", llvm::ArrayRef<double>());
	if(xys.size() > 2 || xys.size() == 0)
		return;
	x = xys[0];
	y = xys[1];

	std::cout << "x: " << x << std::endl;
	std::cout << "y: " << y << std::endl;
}

double AxisCam::xDistanceToCenter()
{
	return x - X_IMAGE_RES /2;
}

double AxisCam::yDistanceToCenter()
{
	return y - Y_IMAGE_RES/2;
}

double AxisCam::percentArea(double area)
{
	return area/(X_IMAGE_RES*Y_IMAGE_RES);
}

double AxisCam::getWidth()
{
	return width;
}

double AxisCam::getHeight()
{
	return height;
}

double AxisCam::getX()
{
	return x;
}

double AxisCam::getY()
{
	return y;
}
double AxisCam::distanceToBlob(double pixel_width)
{
	return X_WIDTH_GOAL * X_IMAGE_RES / (2*pixel_width * tan(AXIS_VANGLE / 2));
}

void AxisCam::setServoY()
{
	double offset = yDistanceToCenter();
	if(offset <= -5)
		std::cout<<"down"<<std::endl;
		///yServo->Set(yServo->Get() + .005f);
	else if(offset >= 5)
		std::cout<<"up"<<std::endl;
		//yServo->Set(yServo->Get() - .005f);
}

void AxisCam::setServoX()
{
	double offset = xDistanceToCenter();
	if(offset <= -5)
		std::cout<<"right"<<std::endl;
		//xServo->Set(xServo->Get() + .005f);
	else if(offset >= 5)
		std::cout<<"left"<<std::endl;
		//xServo->Set(xServo->Get() - .005f);
}


#include <math.h>
#include <Subsystems/AxisCamera.h>

AxisCamera::AxisCamera() :
		Subsystem("USBCam")
{
	//grip.reset(NetworkTable::GetTable("grip").get());
	visionTable = NetworkTable::GetTable("SmartDashboard");
	height = 0;
	width = 0;
	x = 0;
	y = 0;
}

void AxisCamera::InitDefaultCommand()
{
	//set the cam quality of jpeg to be around 50 (out of 100)
	//CameraServer::GetInstance()->SetQuality(50);
	//Start the automatic capture to dashboard
	//CameraServer::GetInstance()->StartAutomaticCapture(CAMERA_NAME);

}


void AxisCamera::findBiggest()
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

double AxisCamera::xDistanceToCenter(double x)
{
	return x - X_IMAGE_RES /2;
}

double AxisCamera::yDistanceToCenter(double y)
{
	return y - Y_IMAGE_RES/2;
}

double AxisCamera::percentArea(double area)
{
	return area/(X_IMAGE_RES*Y_IMAGE_RES);
}

double AxisCamera::getWidth()
{
	return width;
}

double AxisCamera::getHeight()
{
	return height;
}

double AxisCamera::getX()
{
	return x;
}

double AxisCamera::getY()
{
	return y;
}
double AxisCamera::distanceToBlob(double pixel_width)
{
	return X_WIDTH_GOAL * X_IMAGE_RES / (2*pixel_width * tan(AXIS_VANGLE / 2));
}

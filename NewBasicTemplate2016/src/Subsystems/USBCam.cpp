
#include <Subsystems/USBCam.h>
#include <math.h>

USBCam::USBCam() :
		Subsystem("USBCam")
{
	//grip.reset(NetworkTable::GetTable("grip").get());
	visionTable = NetworkTable::GetTable("SmartDashboard");
}

void USBCam::InitDefaultCommand()
{
	//set the cam quality of jpeg to be around 50 (out of 100)
	//CameraServer::GetInstance()->SetQuality(50);
	//Start the automatic capture to dashboard
	//CameraServer::GetInstance()->StartAutomaticCapture(CAMERA_NAME);

}


void USBCam::findBiggest()
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

double USBCam::xDistanceToCenter(double x)
{
	return x - X_IMAGE_RES /2;
}

double USBCam::yDistanceToCenter(double y)
{
	return y - Y_IMAGE_RES/2;
}

double USBCam::percentArea(double area)
{
	return area/(X_IMAGE_RES*Y_IMAGE_RES);
}

double USBCam::getWidth()
{
	return width;
}

double USBCam::getHeight()
{
	return height;
}

double USBCam::getX()
{
	return x;
}

double USBCam::getY()
{
	return y;
}
double USBCam::distanceToBlob(double x, double y, double width, double height)
{
	return X_WIDTH_GOAL * X_IMAGE_RES / (2*PIXEL_WIDTH * tan(AXIS_VANGLE / 2));
}

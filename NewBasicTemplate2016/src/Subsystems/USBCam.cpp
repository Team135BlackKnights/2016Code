#include <CameraServer.h>
#include <ErrorBase.h>
#include <llvm/ArrayRef.h>
#include <Subsystems/USBCam.h>
#include <unistd.h>
#include <iostream>
#include <vector>

USBCam::USBCam() :
		Subsystem("USBCam")
{

	grip.reset(NetworkTable::GetTable("GRIP").get());
	//grip = NetworkTable::GetTable("grip");
	std::cout << "GRIP STARTED before" << std::endl;

	//starts the yung grip and checks for error
	//error will most likely be if we dont have JRE.
	//if (execl(JAVA,"-jar", GRIP_JAR, GRIP_PROJECT, nullptr) == -1) {
		//wpi_setErrnoErrorWithContext("Failed to run GRIP"); //throws error
	//}

	std::cout << "GRIP STARTED after" << std::endl;
}

void USBCam::InitDefaultCommand()
{
	//set the cam quality of jpeg to be around 50 (out of 100)
	//CameraServer::GetInstance()->SetQuality(50);
	//Start the automatic capture to dashboard
	//CameraServer::GetInstance()->StartAutomaticCapture(CAMERA_NAME);

}


std::tuple<double, double, double> USBCam::findBiggest()
{
	auto areas = grip->GetNumberArray("myCountoursReport/area", llvm::ArrayRef<double>()),
	xs = grip->GetNumberArray("myCountoursReport/x", llvm::ArrayRef<double>()),
	ys = grip->GetNumberArray("myCountoursReport/y", llvm::ArrayRef<double>());
	targetArea = -1.0;
	targetX = 0.0;
	targetY = 0.0;
	for (int i = 0; i < areas.size(); i++){
		double area = areas[i], x = xs[i], y = ys[i];
		if (area > targetArea){
			targetArea = area;
			targetX = x;
			targetY = y;
		}
		std::cout << "Got contour: area=" << area << ", x=" << x << ", y=" << y << std::endl;
    }
	//TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST
	std::cout << "TARGET ACQUIRED!" << std::endl;
	std::cout << "AREA = " << targetArea << std::endl;
	std::cout << "(X,Y) = (" << targetX << "," << targetY << ")" << std::endl;
	//TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST
	return std::make_tuple(targetArea, targetX, targetY);
}


double USBCam::xDistanceToCenter(double x)
{
	return x - XWIDTH/2;
}

double USBCam::yDistanceToCenter(double y)
{
	return y - YWIDTH/2;
}

double USBCam::percentArea(double area)
{
	return area/(XWIDTH*YWIDTH);
}



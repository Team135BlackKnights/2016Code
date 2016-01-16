#include <CameraServer.h>
#include <ErrorBase.h>
#include <llvm/ArrayRef.h>
#include <Subsystems/USBCam.h>
#include <unistd.h>
#include <iostream>
#include <vector>

USBCam::USBCam() :
		Subsystem("ExampleSubsystem")
{

}

void USBCam::InitDefaultCommand()
{
	//***first 2 lines primarily for the drivers, can be removed with
	//0 impact on vision processing.***
	//set the cam quality of jpeg to be around 50 (out of 100)
	CameraServer::GetInstance()->SetQuality(50);
	//Start the automatic capture to dashboard
	CameraServer::GetInstance()->StartAutomaticCapture(CAMERA_NAME);

	//starts the yung grip and checks for error
	//error will most likely be if we dont have JRE.
	if (execl(JAVA,"-jar", GRIP_JAR, GRIP_PROJECT, nullptr) == -1) {
		wpi_setErrnoErrorWithContext("Failed to run GRIP"); //throws error
	}


	std::cout << "INITIALIZING CAMERA" << std::endl;
}

std::tuple<double, double, double> USBCam::findBiggest()
{
	auto areas = grip->GetNumberArray("myCountoursReport/area", llvm::ArrayRef<double>()),
	xs = grip->GetNumberArray("myCountoursReport/x", llvm::ArrayRef<double>()),
	ys = grip->GetNumberArray("myCountoursReport/y", llvm::ArrayRef<double>());

	double targetArea = -1.0, targetX = 0.0, targetY = 0.0;
	for (int i = 0; i < areas.size(); i++){
		double area = areas[i], x = xs[i], y = ys[i];
		if (area > targetArea){
			targetArea = area;
			targetX = x;
			targetY = y;
		}
		std::cout << "Got contour: area=" << area << ", x=" << x << ", y=" << y << std::endl;
    }

	return std::make_tuple(targetArea, targetX, targetY);
}

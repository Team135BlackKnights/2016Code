
#include <Subsystems/USBCam.h>

USBCam::USBCam() :
		Subsystem("USBCam")
{
	//grip.reset(NetworkTable::GetTable("grip").get());
	visionTable.reset(NetworkTable::GetTable("table").get());
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
	/*auto areas = grip->GetNumberArray("myCountoursReport/area", llvm::ArrayRef<double>()),
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
	//return std::make_tuple(targetArea, targetX, targetY);*/
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



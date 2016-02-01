
#include "CameraTracking.h"
#include "Subsystems/AxisCam.h"


CameraTracking::CameraTracking()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(cam.get());
}

// Called just before this Command runs the first time
void CameraTracking::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void CameraTracking::Execute()
{
	//std::cout << "running cameratrack";
	//obtain fresh and clean values
	cam->GetCameraValues();
	//maybe print distance if it possibly works
	//std::cout << "distance to blob: " << cam->distanceToBlob(cam->getWidth()) << std::endl;
	//std::cout << "distance to center: X : " << cam->xDistanceToCenter() << " Y: " <<
	//		cam->yDistanceToCenter() <<std::endl;
	/*if(cam->xServo != NULL && cam->yServo != NULL)
	{
		cam->setServoY();
		cam->setServoX();
	}*/
	std::cout << "distance" << cam->distanceToBlob(cam->getSize().at(0));
	std::cout << "angle :" <<cam->angleToBlob(10.2);// cam->angleToBlob(cam->distanceToBlob(cam->getSize().at(0)));
}

// Make this return true when this Command no longer needs to run execute()
bool CameraTracking::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void CameraTracking::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CameraTracking::Interrupted()
{

}

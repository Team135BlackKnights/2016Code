
#include <Commands/CameraTracking.h>
#include <OI.h>
#include <Subsystems/AxisCam.h>
#include <cstdbool>
#include <iostream>
#include <memory>
#include "../RobotMap.h"


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
	std::cout << "distance" << cam->distanceToBlob(cam->getWidth()) << std::endl;
	//float value = Preferences::GetInstance()->GetFloat("ServoX", .5);
	//float xValue = oi->GetStickX(OI::RIGHT);
	std::cout << "offset x: " << cam->xDistanceToCenter() << std::endl;
	//cam->setServoX((float)map(oi->GetStickX(OI::RIGHT), -1, 1, 0, 1));
	//cam->setServoX();
	//cam->setServoX();
	//cam->setServoY();
	cam->UpdateServo();
	//float yValue = oi->GetStickY(OI::RIGHT) / 2.0f;
	//cam->setServoY();
	//cam->setServoY();
	//std::cout << "angle :" <<cam->angleToBlob(cam->distanceToBlob(cam->getWidth()));// cam->angleToBlob(cam->distanceToBlob(cam->getSize().at(0)));

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

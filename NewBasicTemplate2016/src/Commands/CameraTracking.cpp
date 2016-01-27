#include "CameraTracking.h"

CameraTracking::CameraTracking()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(caMeRa.get());
}

// Called just before this Command runs the first time
void CameraTracking::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void CameraTracking::Execute()
{
	//obtain fresh and clean values
	caMeRa->GetCameraValues();
	//maybe print distance if it possibly works
	//std::cout << "distance to blob: " << caMeRa->distanceToBlob(caMeRa->getWidth()) << std::endl;
	std::cout << "distance to center: X : " << caMeRa->xDistanceToCenter() << " Y: " <<
			caMeRa->yDistanceToCenter() <<std::endl;
	if(caMeRa->xServo != NULL && caMeRa->yServo != NULL)
	{
		caMeRa->setServoY();
		caMeRa->setServoX();
	}
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

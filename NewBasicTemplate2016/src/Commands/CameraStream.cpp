#include "CameraStream.h"

CameraStream::CameraStream()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(camUSB.get());
}

// Called just before this Command runs the first time
void CameraStream::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void CameraStream::Execute()
{
/*	try{
		camUSB->camera->GetImage(camUSB->imageFrame);
		camUSB->imageFrame;
		Image* destImage;
		destImage = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
		PixelValue_union pv;
		PixelValue piv = (PixelValue) pv;

		imaqRotate2(destImage, camUSB->imageFrame, 90,piv, InterpolationMethod::IMAQ_BILINEAR,1);
		CameraServer::GetInstance()->SetImage(destImage);
	}
	catch(int e)
	{
		std::cout << "camera didnt work";
	}*/
	IMAQdxSession* session = new IMAQdxSession();
	IMAQdxOpenCamera("cam3", IMAQdxCameraControlMode::IMAQdxCameraControlModeController, session);
	//IMAQdxStopAcquisition(session);
}

// Make this return true when this Command no longer needs to run execute()
bool CameraStream::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void CameraStream::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CameraStream::Interrupted()
{

}

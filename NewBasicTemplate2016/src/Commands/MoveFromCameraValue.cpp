#include <Commands/DriveJ.h>
#include <Commands/MoveFromCameraValue.h>
#include <Commands/Subsystem.h>
#include <cstdbool>

MoveFromCameraValue::MoveFromCameraValue()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain.get());
}

// Called just before this Command runs the first time
void MoveFromCameraValue::Initialize(){
	cam.get()->ToggleTurnPID(true);
	isgood = false;
}

// Called repeatedly when this Command is scheduled to run
void MoveFromCameraValue::Execute()
{
	//float speed = cam.get()->GetTurnSpeed();
	//driveTrain->DriveTank(speed, -speed);
	float dist = cam.get()->xDistanceToCenter();
	std::cout << dist << std::endl;
	/*if(dist > (-50.0f) && dist < 38.0f & !isgood)
	{
		cam.get()->ToggleTurnPID(true);
		isgood = true;
		std::cout<< "toggling" << std::endl;
	}
	else if( !isgood)
	{
		if(dist < -18)
			driveTrain->DriveTank(-.4f,.15f);
		else
			driveTrain->DriveTank(.15f,-.4f);
 		std::cout << "driving" << std::endl;
	}*/
}

// Make this return true when this Command no longer needs to run execute()
bool MoveFromCameraValue::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void MoveFromCameraValue::End()
{
	cam.get()->ToggleTurnPID(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveFromCameraValue::Interrupted()
{
	cam.get()->ToggleTurnPID(false);
}

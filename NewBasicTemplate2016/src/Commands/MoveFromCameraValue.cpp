#include <Commands/MoveFromCameraValue.h>
#include <cstdbool>

MoveFromCameraValue::MoveFromCameraValue()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain.get());
}

// Called just before this Command runs the first time
void MoveFromCameraValue::Initialize(){
	//cam.get()->ToggleTurnPID(true);
	//isgood = false;
	std::cout << "running ";
	isgood = false;
}

// Called repeatedly when this Command is scheduled to run
void MoveFromCameraValue::Execute()
{
	//float speed = cam.get()->GetTurnSpeed();
	//driveTrain->DriveTank(speed, -speed); -32
	float dist = cam.get()->xDistanceToCenter();
	std::cout << "DISTANCE: " << dist << std::endl;
	if(dist <= -5 && !isgood)
		driveTrain.get()->RotateTank(-motorSpeed);
	else if(dist >= 5 && !isgood)
		driveTrain.get()->RotateTank(motorSpeed);
	else
	{
		isgood = true;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool MoveFromCameraValue::IsFinished()
{
	return isgood;
}

// Called once after isFinished returns true
void MoveFromCameraValue::End()
{
//	cam.get()->ToggleTurnPID(false);
	driveTrain.get()->RotateTank(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveFromCameraValue::Interrupted()
{
//	cam.get()->ToggleTurnPID(false);
}

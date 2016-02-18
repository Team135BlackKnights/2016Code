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
}

// Called repeatedly when this Command is scheduled to run
void MoveFromCameraValue::Execute()
{
	//float speed = cam.get()->GetTurnSpeed();
	//std::cout << "speed: " << speed << std::endl;
	//driveTrain->DriveTank(speed, -speed);
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
	cam.get()->ToggleTurnPID(false);}

#include <Commands/MoveFromCameraValue.h>
#include <cstdbool>

MoveFromCameraValue::MoveFromCameraValue()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain.get());
}

// Called just before this Command runs the first time
void MoveFromCameraValue::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void MoveFromCameraValue::Execute()
{
	float speed = cam.get()->GetMotorValues();
	driveTrain->DriveTank(speed, -speed);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveFromCameraValue::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void MoveFromCameraValue::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveFromCameraValue::Interrupted()
{

}

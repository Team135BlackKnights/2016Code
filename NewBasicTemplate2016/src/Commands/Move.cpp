#include <Commands/Move.h>

Move::Move(bool forward)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Move(forward, forward);
}

Move::Move(bool leftForward, bool rightForward)
{
	Requires(driveTrain.get());
	this->directionLeft = (leftForward == true) ? 1 : -1;
	this->directionRight = (rightForward == true) ? 1 : -1;
}

// Called just before this Command runs the first time
void Move::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Move::Execute()
{
	float speed = oi->GetStickSlider(OI::LEFT);
	driveTrain->DriveTank(speed * directionLeft, speed * directionRight);
}

// Make this return true when this Command no longer needs to run execute()
bool Move::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Move::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Move::Interrupted()
{

}

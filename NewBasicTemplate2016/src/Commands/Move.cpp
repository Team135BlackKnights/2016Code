#include <Commands/Move.h>

Move::Move(float speed)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	//Move(speed, speed);
	Requires(driveTrain.get());
	this->speedLeft = speed;
	this->speedRight = speed;
}

Move::Move(float left, float right)
{
	Requires(driveTrain.get());
	this->speedLeft = left;
	this->speedRight = right;
}

// Called just before this Command runs the first time
void Move::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Move::Execute()
{
	float speed = oi->GetStickSlider(oi->CONTROL_MOVEMENT_SLIDER);
	driveTrain->DriveTank(speed * speedLeft, speed * speedRight);
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

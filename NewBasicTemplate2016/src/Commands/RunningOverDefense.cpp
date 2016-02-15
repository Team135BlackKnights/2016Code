#include "RunningOverDefense.h"

RunningOverDefense::RunningOverDefense(int typeOfMethod)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(serialCommunication.get());
	Requires(driveTrain.get());
	leftSonarDistance = 0;
	rightSonarDistance = 0;
	lightValueReceived = 0;

	overDefense = false;

	this->typeOfMethod = typeOfMethod;

	timer.reset(new Timer());

	initialTimerValue = 0;
	setTimerValue = 0;

}

// Called just before this Command runs the first time
void RunningOverDefense::Initialize()
{
	timer->Reset();
}

// Called repeatedly when this Command is scheduled to run
void RunningOverDefense::Execute()
{
	driveTrain->DriveTank(motorPower, motorPower);
	if (overDefense == false) {
		overDefense = serialCommunication->OverDefense(this->typeOfMethod);
	}
	if (overDefense == true) {
		initialTimerValue = timer->Get();
		setTimerValue = initialTimerValue + waitTimerValue;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool RunningOverDefense::IsFinished()
{
	if (overDefense == true && setTimerValue >= timer->Get()) {
		return true;
	}
	else {
		return false;
	}
}

// Called once after isFinished returns true
void RunningOverDefense::End()
{
	driveTrain->DriveTank(0.0, 0.0);
	timer->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunningOverDefense::Interrupted()
{
	End();
}

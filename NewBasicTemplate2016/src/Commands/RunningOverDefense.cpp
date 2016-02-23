#include "RunningOverDefense.h"

RunningOverDefense::RunningOverDefense(int typeOfMethod)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain.get());
	leftSonarDistance = 0;
	rightSonarDistance = 0;
	lightValueReceived = 0;

	this->overDefense = false;

	this->typeOfMethod = typeOfMethod;

	timer.reset(new Timer());

	initialTimerValue = 0;
	setTimerValue = 0;

	placer = 0;

	encoderPosition = 0;

}

// Called just before this Command runs the first time
void RunningOverDefense::Initialize()
{
	timer->Reset();
}

// Called repeatedly when this Command is scheduled to run
void RunningOverDefense::Execute()
{
	driveTrain->GetEncoderPosition(DriveTrain::FRONT_RIGHT);

	driveTrain->DriveTank(motorPower, motorPower);
	if (overDefense == false) {
		std::cout << "Executing" << std::endl;
		this->overDefense = analogSensors->OverDefense(AnalogSensors::CASE_LEFT_RIGHT_AND_LIGHT);
		placer = 1;
	}
	if (this->overDefense == true && placer == 1) {
		std::cout << "Over Defense" << std::endl;
		initialTimerValue = timer->Get();
		setTimerValue = initialTimerValue + waitTimerValue;
		placer = 2;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool RunningOverDefense::IsFinished()
{
	return (this->overDefense == true && setTimerValue >= timer->Get());
}

// Called once after isFinished returns true
void RunningOverDefense::End()
{
	std::cout << "Ended" << std::endl;
	driveTrain->DriveTank(0.0, 0.0);
	timer->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunningOverDefense::Interrupted()
{
	End();
}

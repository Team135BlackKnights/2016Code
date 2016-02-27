#include "RunningOverDefense.h"

RunningOverDefense::RunningOverDefense(AnalogSensors::DEFENSE_METHOD typeOfDefense)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain.get());

	overDefense = false;

	encoderPosition = 0;

	this->typeOfDefense = typeOfDefense;

}

// Called just before this Command runs the first time
void RunningOverDefense::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void RunningOverDefense::Execute()
{
	encoderPosition = driveTrain->GetEncoderPosition(DriveTrain::FRONT_RIGHT);

	driveTrain->DriveTank(motorPower, motorPower);

	overDefense = analogSensors->OverDefense(this->typeOfDefense, encoderPosition);
	/*if (overDefense == false) {
		std::cout << "Executing" << std::endl;
		this->overDefense = analogSensors->OverDefense(AnalogSensors::CASE_LOW_BAR, encoderPosition);
		placer = 1;
	}
	if (this->overDefense == true && placer == 1) {
		std::cout << "Over Defense" << std::endl;
		initialTimerValue = timer->Get();
		setTimerValue = initialTimerValue + waitTimerValue;
		placer = 2;
	} */
}

// Make this return true when this Command no longer needs to run execute()
bool RunningOverDefense::IsFinished()
{
	//return (this->overDefense == true && setTimerValue >= timer->Get());
	return (overDefense);
}

// Called once after isFinished returns true
void RunningOverDefense::End()
{
	std::cout << "Ended" << std::endl;
	driveTrain->DriveTank(0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunningOverDefense::Interrupted()
{
	End();
}

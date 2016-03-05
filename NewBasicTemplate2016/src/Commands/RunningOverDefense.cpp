#include "RunningOverDefense.h"

//  Input the typeOfDefense the robot is going over
RunningOverDefense::RunningOverDefense(AnalogSensors::DEFENSE_METHOD typeOfDefense)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(analogSensors.get());
	Requires(driveTrain.get());
	Requires(arm.get());

	//  Default values for these varaibles

	overDefense = false;

	encoderPosition = 0;

	this->typeOfDefense = typeOfDefense;

	currentPositionOfArm = 0;
	desiredSPositionOfArm = 0;

	armSet = 0;

}

// Called just before this Command runs the first time
void RunningOverDefense::Initialize()
{
	//  If the typeOfDefense inputed into this command is CASE_CHEVAL_DE_FRISE, then
	//  the arm has to move downwards to move down the platform on the Cheval De Frise
	if (this->typeOfDefense == AnalogSensors::CASE_CHEVAL_DE_FRISE) {
		//  Get the value of either the encoder or potentiometer for the arm to be at for the specified angle
		desiredSPositionOfArm = arm->GetPotValueOrEncoderPositionGivenDesiredAngle(Arm::CHEVAL_DE_FRISE_DEGREES);
	}
}

// Called repeatedly when this Command is scheduled to run
void RunningOverDefense::Execute()
{
	encoderPosition = driveTrain->GetEncoderPosition(DriveTrain::FRONT_RIGHT);

	driveTrain->DriveTank(motorPower, motorPower);

	if (this->typeOfDefense == AnalogSensors::CASE_CHEVAL_DE_FRISE) {
		currentPositionOfArm = arm->GetPotValueOrEncoderPosition();

		if (currentPositionOfArm < desiredSPositionOfArm && armSet == false) {
			arm->RaiseLowerArm(motorPower * Arm::UP);
		}
		else if (currentPositionOfArm > desiredSPositionOfArm && armSet == false) {
			arm->RaiseLowerArm(motorPower * Arm::DOWN);
		}
		else if (currentPositionOfArm == desiredSPositionOfArm && armSet == false) {
			arm->RaiseLowerArm(0.0f);
			armSet = true;
		}
		else if (armSet) {
			overDefense = analogSensors->OverDefense(this->typeOfDefense, encoderPosition);
		}
	}
	else {
		overDefense = analogSensors->OverDefense(this->typeOfDefense, encoderPosition);
	}

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
	driveTrain->DriveTank(0.0f, 0.0f);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunningOverDefense::Interrupted()
{
	End();
}

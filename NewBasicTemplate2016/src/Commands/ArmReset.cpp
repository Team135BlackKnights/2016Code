#include "ArmReset.h"

//  Raises the arm until it reaches the top limit switch
//  We need to raise the arm prior to every match so the robot will be within the rule book measurements
ArmReset::ArmReset()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(arm.get());
}

// Called just before this Command runs the first time
void ArmReset::Initialize()
{
	//  Stop the command if it runs over 15 seconds
	this->SetTimeout(15.0f);
	//this->SetRunWhenDisabled(true);
}

// Called repeatedly when this Command is scheduled to run
void ArmReset::Execute()
{
	//  Multiplying the power by Arm::UP because in order to raise the arm, the motor power needs to be positive
	arm->RaiseLowerArm(power * Arm::UP);
}

// Make this return true when this Command no longer needs to run execute()
bool ArmReset::IsFinished()
{
	//  Stop the command when the top limit switch is pressed
	return arm->GetTopLimitSwitchValue();
}

// Called once after isFinished returns true
void ArmReset::End()
{
	//  Stop the arm motor from moving
	arm->RaiseLowerArm(0.00000f);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmReset::Interrupted()
{
}

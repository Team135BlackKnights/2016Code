#include "AutoEncoderTesting.h"
#include "Subsystems/DriveTrain.h"

//  Used to Test Encoder Revs Per Second
//  Plan:
//  Step 1: Run motor at a constant power which is represented by "motorTestSpeed"
//  Step 2: Display the value of the Revs per second of the encoder at that specific motor power on SmartDashboard
//  Step 3: Get value of the Revs per second at that motor power and document this data
//  Step 4: Repeat this process with different motor powers until I can come up with a formula to convert
//          Revs per Second into Motor Power
AutoEncoderTesting::AutoEncoderTesting()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain.get());
	inverted = false;
	//  timer.reset(new Timer());
}

// Called just before this Command runs the first time
void AutoEncoderTesting::Initialize()
{
	this->inverted = Preferences::GetInstance()->GetBoolean("Inverted", false);
	driveTrain->InvertMotors(this->inverted);
	//  timer->Start();
	for (int i = 0; i < NUM_OF_MOTORS; i++) {
		//  This will zero out all the encoders before the code below executes
		driveTrain->ZeroEncoder(i);
	}
}

// Called repeatedly when this Command is scheduled to run
void AutoEncoderTesting::Execute()
{
	driveTrain->DriveTank(motorTestSpeed, motorTestSpeed);

	SmartDashboard::PutNumber(FrontLeftString, driveTrain->GetRevsPerSecond(FRONT_LEFT));
	SmartDashboard::PutNumber(FrontRightString, driveTrain->GetRevsPerSecond(FRONT_RIGHT));
	SmartDashboard::PutNumber(RearLeftString, driveTrain->GetRevsPerSecond(REAR_LEFT));
	SmartDashboard::PutNumber(RearRightString, driveTrain->GetRevsPerSecond(REAR_RIGHT));

}

// Make this return true when this Command no longer needs to run execute()
bool AutoEncoderTesting::IsFinished()
{
	/* if (timer->Get() >= timeLimit) {
		return true;
	}
	else {
		return false;
	} */
	return false;
}

// Called once after isFinished returns true
void AutoEncoderTesting::End()
{
	SmartDashboard::PutNumber(FrontLeftString, driveTrain->GetVelocity(FRONT_LEFT));
	SmartDashboard::PutNumber(FrontRightString, driveTrain->GetVelocity(FRONT_RIGHT));
	SmartDashboard::PutNumber(RearLeftString, driveTrain->GetVelocity(REAR_LEFT));
	SmartDashboard::PutNumber(RearRightString, driveTrain->GetVelocity(REAR_RIGHT));
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoEncoderTesting::Interrupted()
{

}

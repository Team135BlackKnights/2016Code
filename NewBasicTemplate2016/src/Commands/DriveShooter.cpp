#include "DriveShooter.h"

DriveShooter::DriveShooter()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(shooter.get());
	power = 0;
}

// Called just before this Command runs the first time
void DriveShooter::Initialize()
{
	//  Make sure the shooter servo is in its correct position before executing the code below
	//  The servo has to be out of the way of the boulder when the shooter has the boulder
	shooter->DriveKicker(Shooter::KICKER_RESET);
}

// Called repeatedly when this Command is scheduled to run
void DriveShooter::Execute()
{
	//  Note: The button layouts are different because there are multiple drivers

	//std::cout << shooter->GetEncoderPosition(Shooter::TWO_WHEEL_SHOOTER_MOTOR) << std::endl;
	power = 0;

	//  The motorPower is set equal to the value of the slider on one of the joysticks
	motorPower = oi->GetStickSlider(oi->manipulator->CONTROL_SHOOTER_POWER_SLIDER);

	//   If a certain button is pressed
	if (oi->GetButton(oi->manipulator->CONTROL_SHOOTER_OUT[STICK], oi->manipulator->CONTROL_SHOOTER_OUT[BUTTON]))//oi->CONTROL_SHOOT[0], oi->CONTROL_SHOOT[1]))
		//  Have "power" equal to the sliderValue * Shooter::OUT
		//  Shooter::OUT represents the direction (+/-) the motor needs to be so the wheels turn outwards
		power = motorPower * Shooter::OUT;

	//   If a certain button is pressed
	else if (oi->GetButton(oi->manipulator->CONTROL_SHOOTER_IN[STICK], oi->manipulator->CONTROL_SHOOTER_IN[BUTTON]))//oi->CONTROL_COLLECTION_IN[0], oi->CONTROL_COLLECTION_IN[1]))
		//  Have "power" equal to the sliderValue * Shooter::IN
		//  Shooter::IN represents the direction (+/-) the motor needs to be so the wheels turn inwards
		power = motorPower * Shooter::IN;
	//  Input "power" that was calculated above into the function below
	shooter->DriveShooterMotor(power);

	//if (oi->GetButton(oi->manipulator->CONTROL_SHOOTER_KICKER_KICK[STICK], oi->manipulator->CONTROL_SHOOTER_KICKER_KICK[BUTTON]))

	//  If a certain button is pressed
	if (oi->IsPressed(oi->manipulator->CONTROL_SHOOTER_KICKER_KICK))
		//  Move the Servo so the boulder will be launched
		shooter->DriveKicker(Shooter::KICKER_KICKED);
	else //if (oi->GetButton(oi->manipulator->CONTROL_SHOOTER_KICKER_RESET[STICK], oi->manipulator->CONTROL_SHOOTER_KICKER_RESET[BUTTON]))
		//  If the button is not pressed, leave the servo in its default position so the ball is not launched
		shooter->DriveKicker(Shooter::KICKER_RESET);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveShooter::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveShooter::End()
{
	//  When the code ends its execution, then stop the motors from moving
	shooter->DriveShooterMotor(0.0f);
	//  And Reset the servo to its default position
	shooter->DriveKicker(Shooter::KICKER_RESET);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveShooter::Interrupted()
{
	this->End();
}

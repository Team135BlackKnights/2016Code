#include <AnalogInput.h>
#include <CANTalon.h>
#include <Commands/DriveArm.h>
#include <DigitalInput.h>
#include <interfaces/Potentiometer.h>
#include <RobotMap.h>
#include <Subsystems/Arm.h>
#include <cmath>
#include <cstdbool>
#include <iostream>
#include <memory>



Arm::Arm():
	Subsystem("Arm")
{
	//  Declares the arm motor with its designated Talon ID
	armMotor.reset(new CANTalon(MOTOR_RAISE_LOWER_ARM));

	//  Set up the Encoder on the arm
	armMotor->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	armMotor->ConfigEncoderCodesPerRev(COUNT);
	this->ZeroEncoder();
	//  Have the encodet update its values at a faster rate
	armMotor->SetStatusFrameRateMs(CANTalon::StatusFrameRate::StatusFrameRateQuadEncoder, 15);
	armMotor->SetSensorDirection(false);

	//  Declaring the potentiometer in its designated analog input slot
	ai = new AnalogInput(POT_ANALOG_PORT);
	//  360 represents the range in which the potentiometer will output
	//  0 to 360
	pot = new AnalogPotentiometer(ai, POT_CONSTANT, 0); // 0 can change if you want more offset

	//  Declaring a Trigger using the limit switches declared above
	upperLimit = new ResetEncoderFromLimitSwitch(topLimitSwitch);
	lowerLimit = new ResetEncoderFromLimitSwitch(bottomLimitSwitch);
	//  When ResetEncoderFromLimitSwitch->Get() == true, then SetArmPosition() will execute
	//upperLimit->WhenActive(new SetArmPosition(ARM_UP_POSITION));
	//lowerLimit->WhenActive(new SetArmPosition(ARM_DOWN_POSITION));
	pot = new AnalogPotentiometer(ai, POT_CONSTANT, 0); // 0 can change if you want more offset

	bottomLimitSwitch.reset(new DigitalInput(DIGITAL_ARM_LIMIT_BOTTOM));
	topLimitSwitch.reset(new DigitalInput(DIGITAL_ARM_LIMIT_TOP));
}

void Arm::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveArm());
}

//  Set the value for which the arm will move up or down
void Arm::RaiseLowerArm(float motorPower) {
	//  If the Upper Limit Switch is pressed
	if (GetTopLimitSwitchValue()) {
		this->SetEncoderPosition(ARM_UP_POSITION);
		if (UP > 0)  //  If up is positive
			//  Takes the minimum of the two values in parenthesis
			//  Only allow the arm to move in the negative direction, downward
			motorPower = fminf(motorPower, 0);
		else  //  If up is negative
			//  Takes the maximum of the two values in parenthesis
			//  Only allow the arm to move in the positive direction, downward
			motorPower = fmaxf(motorPower, 0);
	}
	//  If the Lower Limit Switch is pressed
	else if (GetBottomLimitSwitchValue()) {
		SetEncoderPosition(ARM_DOWN_POSITION);
		if (UP > 0) //  If up is positive
			//  Only allow the arm to move in the positive direction, upwards
			motorPower = fmaxf(motorPower, 0);
		else  //  If up is negative
			//  Only allow the arm to move in the negative direction, upwards
			motorPower = fminf(motorPower, 0);
	}

	armMotor->Set(motorPower);
}

bool Arm::GetTopLimitSwitchValue() {
	return !topLimitSwitch->Get();
}

bool Arm::GetBottomLimitSwitchValue() {
	return !bottomLimitSwitch->Get();
}

//cameraDist is in inches
double Arm::GetAngleForArm(double cameraDist, double fadeAwayDist)
{
	double groundDist = (HEIGHT_OF_TOWER - CAMERA_HEIGHT_OFF_GROUND) / (tan(asin((HEIGHT_OF_TOWER - CAMERA_HEIGHT_OFF_GROUND) / cameraDist))) + fadeAwayDist;
	std::cout << "Ground distance: " << groundDist << std::endl;
	return atan((HEIGHT_OF_TOWER - ARM_HEIGHT_OFF_GROUND + GOAL_HEIGHT_COMPENSATION) / (groundDist + CAMERA_DISTANCE_FROM_SHOOTING_AXIS));
}

int Arm::GetEncoderPosition() {
	return (FEEDBACK_DEVICE_INVERTED ? -1 : 1) * armMotor->GetEncPosition();// + UP_ARM_POSITION;
}

void Arm::SetEncoderPosition(int value)
{
	this->armMotor->SetPosition(value);
}

void Arm::ZeroEncoder() {
	armMotor->SetPosition(0);
}

double Arm::GetPotValue() {
	return pot->Get();
}

//  Hypotenuse in inches
double Arm::GetPotOrEncoderValueForAutomationOfArm(double inchesHypotenuse) {
	double radians = GetAngleForArm(inchesHypotenuse);
	double degrees = radians * (180/M_PI);
	return FEEDBACK == CONTROL_TYPE::POT ? degrees : (double)(degrees * ENCODER_MULTIPLYING_CONSTANT);
}

//  Depending upon whether we are using an encoder or potentiometer, get the current value of the specified sensor
double Arm::GetPotValueOrEncoderPosition() {
	return FEEDBACK == CONTROL_TYPE::POT ? pot->Get() : (double)armMotor->GetEncPosition();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

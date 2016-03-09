#include <AnalogInput.h>
#include <CANTalon.h>
#include <Commands/DriveArm.h>
#include <DigitalInput.h>
#include <interfaces/Potentiometer.h>

#include <Subsystems/Arm.h>
#include <cmath>
#include <cstdbool>
#include <iostream>
#include <memory>



Arm::Arm():
	Subsystem("Arm")
{
	armMotor.reset(new CANTalon(MOTOR_RAISE_LOWER_ARM));

	armMotor->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	armMotor->ConfigEncoderCodesPerRev(256);
	armMotor->SetStatusFrameRateMs(CANTalon::StatusFrameRate::StatusFrameRateQuadEncoder, 15);
	this->ZeroEncoder();
	armMotor->SetSensorDirection(false);
	ai = new AnalogInput(POT_ANALOG_PORT);
	pot = new AnalogPotentiometer(ai, POT_CONSTANT, 0); // 0 can change if you want more offset

	bottomLimitSwitch.reset(new DigitalInput(DIGITAL_ARM_LIMIT_BOTTOM));
	topLimitSwitch.reset(new DigitalInput(DIGITAL_ARM_LIMIT_TOP));
}

void Arm::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveArm());
}

void Arm::RaiseLowerArm(float motorPower) {
	float power = motorPower;
	if (GetTopLimitSwitchValue()) {
		this->SetEncoderPosition(this->ARM_UP_POSITION);
		if (UP > 0)
			power = fminf(power, 0);
		else
			power = fmaxf(power, 0);
	}
	else if (GetBottomLimitSwitchValue()) {
		this->ZeroEncoder();
		if (UP > 0)
			power = fmaxf(power, 0);
		else
			power = fminf(power, 0);
	}
	std::cout << "encoder: " << this->GetEncoderPosition()<< " angle: "<< this->GetEncoderPosition() * 90 / 64 << std::endl;
	armMotor->Set(power);
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
	return (ENCODER_INVERTED ? -1 : 1) * armMotor->GetEncPosition();// + UP_ARM_POSITION;
}

double Arm::GetValueBasedOnAngle(double angle)
{
	return (double)(angle * ENCODER_MULTIPLYING_CONSTANT);
}

void Arm::SetEncoderPosition(int value)
{
	this->armMotor->SetPosition(value);
}

void Arm::ZeroEncoder() {
	armMotor->SetPosition(0);
}

//  Hypotenuse in inches
double Arm::GetPotOrEncoderValueForAutomationOfArm(double inchesHypotenuse) {
	double radians = GetAngleForArm(inchesHypotenuse);
	double degrees = radians * (180/M_PI);

	return degrees * ENCODER_MULTIPLYING_CONSTANT;
}

double Arm::GetPotValueOrEncoderPosition() {
	return (ENCODER_INVERTED ? -1 : 1) * (FEEDBACK == CONTROL_TYPE::POT ? pot->Get() : (double)armMotor->GetEncPosition());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

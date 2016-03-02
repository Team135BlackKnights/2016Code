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
	armMotor.reset(new CANTalon(MOTOR_RAISE_LOWER_ARM));

	//armMotor->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	//armMotor->ConfigEncoderCodesPerRev(256);
	//armMotor->SetStatusFrameRateMs(CANTalon::StatusFrameRate::StatusFrameRateQuadEncoder, 15);
	//this->ZeroEncoder();
	//armMotor->SetSensorDirection(false);
	ai = new AnalogInput(POT_ANALOG_PORT);
	pot = new AnalogPotentiometer(ai, 360, 0); // 0 can change if you want more offset

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
		if (UP > 0)
			power = fminf(power, 0);
		else
			power = fmaxf(power, 0);
	}
	armMotor->Set(power);
}

bool Arm::GetTopLimitSwitchValue() {
	return topLimitSwitch->Get();
}

bool Arm::GetBottomLimitSwitchValue() {
	return bottomLimitSwitch->Get();
}

//cameraDist is in inches
double Arm::GetAngleForArm(double cameraDist)
{
	double groundDist = (HEIGHT_OF_TOWER - CAMERA_HEIGHT_OFF_GROUND) / (tan(asin((HEIGHT_OF_TOWER - CAMERA_HEIGHT_OFF_GROUND) / cameraDist)));
	std::cout << "Ground distance: " << groundDist << std::endl;
	return atan((HEIGHT_OF_TOWER - CAMERA_HEIGHT_OFF_GROUND + GOAL_HEIGHT_COMPENSATION) / (groundDist + CAMERA_DISTANCE_FROM_SHOOTING_AXIS));
}

int Arm::GetEncoderPosition() {
	return -armMotor->GetEncPosition();// + UP_ARM_POSITION;
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
double Arm::GetPotOrEncoderValueForAutomationOfArm(CONTROL_TYPE controlType, double inchesHypotenuse) {
	switch(controlType) {
	case POT: {
		double potRadians = GetAngleForArm(inchesHypotenuse);
		double potAngle = potRadians * (180.0D/M_PI);
		double potValue = potAngle;
		return potValue;
	}

	case ENCODER: {
		double encoderRadians = GetAngleForArm(inchesHypotenuse);
		double encoderAngle = encoderRadians * (180.0D/M_PI);
		int encoderPosition = encoderAngle * ENCODER_MULTIPLYING_CONSTANT;
		return (double)encoderPosition;
	}

	default: {
		return 0.0;
	}
}
}

double Arm::GetPotValueOrEncoderPosition(CONTROL_TYPE controlType) {
	switch (controlType) {
	case POT:
		return pot->Get();
	break;

	case ENCODER:
		return (double) armMotor->GetEncPosition();
	break;

	default:
		return 0.0;
	break;
	}
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

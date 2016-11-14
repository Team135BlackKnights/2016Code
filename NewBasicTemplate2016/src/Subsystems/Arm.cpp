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

typedef float sink;



Arm::Arm():
	Subsystem("Arm")
{
	armMotor.reset(new CANTalon(MOTOR_RAISE_LOWER_ARM));

	armMotor->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	armMotor->ConfigEncoderCodesPerRev(ARM_ENCODER_COUNT);
	//armMotor->SetStatusFrameRateMs(CANTalon::StatusFrameRate::StatusFrameRateQuadEncoder, 15);
	//this->ZeroEncoder();
	armMotor->SetSensorDirection(false);
	armMotor->SetInverted(ARM_INVERTED);
	ai = new AnalogInput(POT_ANALOG_PORT);
	pot = new AnalogPotentiometer(ai, POT_CONSTANT, 0); // 0 can change if you want more offset

	bottomLimitSwitch.reset(new DigitalInput(7));//DIGITAL_ARM_LIMIT_BOTTOM));
	topLimitSwitch.reset(new DigitalInput(DIGITAL_ARM_LIMIT_TOP));
	SetEncoderPosition(Arm::ARM_UP_POSITION);
	armPosIsGood = false;
	overrideLimitSwitch = false;
}

void Arm::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveArm());
}

void Arm::RaiseLowerArm(sink motorPower, bool softStop) {
	sink power = motorPower;
	/*
	if (GetTopLimitSwitchValue()) {
		//this->SetEncoderPosition(this->ARM_UP_POSITION);
		std::cout << "\n\nTOP LIMIT PRESSED\n";
		power = fmax(power, 0.0f);
	}
	*/
	if (GetBottomLimitSwitchValue()) {
		std::cout << "\nBOTTOM LIMIT PRESSED\n";
		this->ZeroEncoder();
		if (overrideLimitSwitch == false) {
			power = fminf(power, 0.0f);
		}
	}
	/*else if (GetTopLimitSwitchValue() && !Preferences::GetInstance()->GetBoolean("PREMATCH CAN RAISE ARM", false)) {
		std::cout << "HIGHEST POINT REACHED\n";
		power = fminf(power, 0.0f);
	}

	if (softStop && GetTopLimitSwitchValue()) {
		std::cout << "YOU'VE REACHED THE TOP\n";
		power = fmaxf(power, 0.0f);

		if (UP > 0)
			power = fminf(power, 0);
		else
			power = fmaxf(power, 0);
		*/
	//}
	//std::cout << "encoder: " << this->GetEncoderPosition()<< " angle: "<< this->GetEncoderPosition() / Arm::ENCODER_MULTIPLYING_CONSTANT << std::endl;
	SmartDashboard::PutNumber("Current Encoder Value:", GetEncoderPosition());
	armMotor->Set(power);
}

bool Arm::GetTopLimitSwitchValue() {
	bool value = GetEncoderPosition() >= ARM_UP_POSITION;
	//std::cout << value << std::endl;
	return value;
}

bool Arm::GetBottomLimitSwitchValue() {
	if (overrideLimitSwitch) return false;

	bool value =  !bottomLimitSwitch.get()->Get();
	if (value)
		std::cout << "B";
	return value;
}

//cameraDist is in inches
double Arm::GetAngleForArm(double cameraDist, double fadeAwayDist)
{
	double groundDist = (HEIGHT_OF_TOWER - CAMERA_HEIGHT_OFF_GROUND + 6.0) / (tan(asin((HEIGHT_OF_TOWER - CAMERA_HEIGHT_OFF_GROUND + 6.0) / cameraDist))) + fadeAwayDist;
	std::cout << "Ground distance: " << groundDist << std::endl;
	return atan((HEIGHT_OF_TOWER - ARM_HEIGHT_OFF_GROUND + GOAL_HEIGHT_COMPENSATION + 40.0) / (groundDist + CAMERA_DISTANCE_FROM_SHOOTING_AXIS));
}

int Arm::GetEncoderPosition() {
	return (ENCODER_INVERTED ? -1 : 1) * armMotor->GetEncPosition();// + UP_ARM_POSITION;
}

int Arm::GetEncoderPositionBasedOnAngle(double angle)
{
	return (int)(angle * ENCODER_MULTIPLYING_CONSTANT);
}

void Arm::SetEncoderPosition(int value)
{
	this->armMotor->SetEncPosition(value);
}

void Arm::ZeroEncoder() {
	armMotor->SetEncPosition(0);
}

//  Hypotenuse in inches
int Arm::GetEncoderPositionForAutomationOfArm(double inchesHypotenuse) {
	double radians = GetAngleForArm(inchesHypotenuse);
	double degrees = radians * (180/M_PI);

	return degrees * ENCODER_MULTIPLYING_CONSTANT;
}

bool Arm::ArmPosIsGood(bool isGood) {
	return armPosIsGood = isGood;
}

bool Arm::ArmPosIsGood() {
	return armPosIsGood;
}

void Arm::OverrideLimitSwitch() {
	overrideLimitSwitch = !overrideLimitSwitch;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

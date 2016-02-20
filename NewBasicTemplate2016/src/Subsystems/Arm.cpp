#include "Arm.h"
#include "../RobotMap.h"
#include "../Commands/DriveArm.h"

Arm::Arm():
	Subsystem("Arm")
{
	armMotor = new CANTalon(MOTOR_RAISE_LOWER_ARM);

	armMotor->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	armMotor->ConfigEncoderCodesPerRev(COUNT);
	armMotor->SetStatusFrameRateMs(CANTalon::StatusFrameRate::StatusFrameRateQuadEncoder, 15);
}

void Arm::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveArm());
}

void Arm::RaiseLowerArm(float motorPower) {
	armMotor->Set(motorPower);
}

bool Arm::GetTopLimitSwitchValue() {
	return topLimitSwitch->Get();
}

bool Arm::GetBottomLimitSwitchValue() {
	return bottomLimitSwitch->Get();
}

//  HEIGHT and hypotenuse in inches
int Arm::GetEncoderValueForAngle(double inchesHypotenuse) {
	double radians = asin(HEIGHT_OF_TOWER/inchesHypotenuse);
	double angle = radians * (180/M_PI);
	int encoderPosition = round((int)(angle * ENCODER_MULTIPLYING_CONSTANT));
	return encoderPosition;
}

int Arm::GetEncoderPosition() {
	return armMotor->GetEncPosition();
}

void Arm::ZeroEncoder() {
	armMotor->SetPosition(0);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

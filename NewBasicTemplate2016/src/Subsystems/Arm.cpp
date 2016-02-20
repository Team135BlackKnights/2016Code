#include "Arm.h"
#include "../RobotMap.h"
#include "../Commands/DriveArm.h"

Arm::Arm():
	Subsystem("Arm")
{
	armMotor.reset(new CANTalon(MOTOR_RAISE_LOWER_ARM));

	armMotor->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	armMotor->ConfigEncoderCodesPerRev(256);
	armMotor->SetStatusFrameRateMs(CANTalon::StatusFrameRate::StatusFrameRateQuadEncoder, 15);
	this->ZeroEncoder();
	armMotor->SetSensorDirection(false);
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
	std::cout << "distance: " << inchesHypotenuse << std::endl;
	double radians = asin(HEIGHT_OF_TOWER/((float)inchesHypotenuse * 12.0f));
	std::cout << "rad: " << radians << std::endl;
	double angle = radians * (180.0D/M_PI);
	std::cout << "angle: " << angle << std::endl;
	int encoderPosition = (int)round((angle * ENCODER_MULTIPLYING_CONSTANT));
	return encoderPosition;
	//return Preferences::GetInstance()->GetInt("encoderPos", 0);
}

int Arm::GetEncoderPosition() {
	return -armMotor->GetEncPosition();
}

void Arm::ZeroEncoder() {
	armMotor->SetPosition(0);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

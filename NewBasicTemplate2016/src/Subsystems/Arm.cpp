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
	std::cout << "camera to goal distance: " << inchesHypotenuse << std::endl;
	//double radians = asin((HEIGHT_OF_TOWER)/((float)feetHypotenuse * 12.0f));
	double radians = GetAngleForArm(inchesHypotenuse);
	std::cout << "rad: " << radians << std::endl;
	double angle = radians * (180.0D/M_PI);
	std::cout << "angle: " << angle << std::endl;
	int encoderPosition = (angle * ENCODER_MULTIPLYING_CONSTANT);
	return encoderPosition;
	//return Preferences::GetInstance()->GetInt("encoderPos", 0);
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

void Arm::ZeroEncoder() {
	armMotor->SetPosition(0);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

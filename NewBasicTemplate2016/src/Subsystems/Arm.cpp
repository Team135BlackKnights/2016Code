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

	//  Declaring limit switches in their designated Digital Input slots
	topLimitSwitch = new DigitalInput(TOP_LIMIT_SWITCH_PORT);
	bottomLimitSwitch = new DigitalInput(BOTTOM_LIMIT_SWITCH_PORT);
	//  Declaring a Trigger using the limit switches declared above
	upperLimit = new ResetEncoderFromLimitSwitch(topLimitSwitch);
	lowerLimit = new ResetEncoderFromLimitSwitch(bottomLimitSwitch);
	//  When ResetEncoderFromLimitSwitch->Get() == true, then SetArmPosition() will execute
	//upperLimit->WhenActive(new SetArmPosition(ARM_UP_POSITION));
	//lowerLimit->WhenActive(new SetArmPosition(ARM_DOWN_POSITION));
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
		this->SetArmEncoderPosition(ARM_UP_POSITION);
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
		SetArmEncoderPosition(ARM_DOWN_POSITION);
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
double Arm::GetAngleForArm(double cameraDist)
{
	double groundDist = (HEIGHT_OF_TOWER - CAMERA_HEIGHT_OFF_GROUND) / (tan(asin((HEIGHT_OF_TOWER - CAMERA_HEIGHT_OFF_GROUND) / cameraDist)));
	std::cout << "Ground distance: " << groundDist << std::endl;
	return atan((HEIGHT_OF_TOWER - CAMERA_HEIGHT_OFF_GROUND + GOAL_HEIGHT_COMPENSATION) / (groundDist + CAMERA_DISTANCE_FROM_SHOOTING_AXIS));
}

int Arm::GetEncoderPosition() {
	return (ENCODER_INVERTED ? -1: 1) * armMotor->GetEncPosition();
}

void Arm::ZeroEncoder() {
	armMotor->SetPosition(0);
}

double Arm::GetPotValue() {
	return pot->Get();
}

//  Hypotenuse in inches
double Arm::GetPotOrEncoderValueForAutomationOfArm(CONTROL_TYPE controlType, double inchesHypotenuse) {
	//  Switches between the encoder and the potentiometer
	switch(controlType) {
	case POT: {
		//  Converts the angle into a potentiometer value and returns this value for arm need to be at
		double potRadians = GetAngleForArm(inchesHypotenuse);
		double potAngle = potRadians * (180.0D/M_PI);
		double potValue = potAngle;
		return (double) potValue;
	}

	case ENCODER: {
		//  Converts the angle into an encoder count value and returns this value for arm need to be at
		double encoderRadians = GetAngleForArm(inchesHypotenuse);
		double encoderAngle = encoderRadians * (180.0D/M_PI);
		int encoderPosition = encoderAngle * ENCODER_MULTIPLYING_CONSTANT;
		return (double)encoderPosition;
	}

	//  If the control type enum is none of the two above, return 0
	default: {
		return 0.0;
	}
}
}

//  Depending upon whether we are using an encoder or potentiometer, get the current value of the specified sensor
double Arm::GetPotValueOrEncoderPosition(CONTROL_TYPE controlType) {
	switch (controlType) {
	case POT:
		return pot->Get();
	break;

	//  Gets the encoder Position
	//  Value is the current Count of the encoder
	//  1 Rotation is equal to the QUADRATURE_COUNT of the encoder
	case ENCODER:
		return (double) armMotor->GetEncPosition();
	break;

	default:
		return 0.0;
	break;
	}
}

void Arm::SetArmEncoderPosition(int encoderPostion) {
	armMotor->SetEncPosition(encoderPostion);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

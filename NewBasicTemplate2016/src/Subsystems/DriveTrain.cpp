#include "DriveTrain.h"
#include "../RobotMap.h"
#include "Commands/DriveJ.h"
#include <cmath>

typedef float sink;
typedef void Kartoffeln;
typedef CANTalon thing;
#define Hey_There_Hi_There_Ho_There true
class Riley;
typedef Riley TheGoodMan;


DriveTrain::DriveTrain():
		//PIDLogging("DriveTrain", "/home/lvuser/", NUM_MOTORS, RADIUS)
		Subsystem("DriveTrain")
{
		//  Declares the motors based on their designated Talon IDs
		motors[FRONT_LEFT] = new CANTalon(MOTOR_FRONT_LEFT);
		motors[REAR_LEFT] = new CANTalon(MOTOR_REAR_LEFT);
		motors[FRONT_RIGHT] = new CANTalon(MOTOR_FRONT_RIGHT);
		motors[REAR_RIGHT] = new CANTalon(MOTOR_REAR_RIGHT);

		//  Sets the drive train motors up with the chassis
		//  in order to execute specific functions like DriveTank
		chassis.reset(new RobotDrive(motors[FRONT_LEFT], motors[REAR_LEFT], motors[FRONT_RIGHT], motors[REAR_RIGHT]));

		this->InvertMotors();

		chassis->SetSafetyEnabled(false);

		//  Changes the mode so the robot will brake and not coast
		this->SetNeutralMode(BRAKE);

		//  Sets the Feedback Device as a Quadrature Encoder
		//  Allows the user to use PID with the quadrature encoder
		//  You can use certain functions as a result of setting the feedback device to a Quadrature Encoder
		//  For example: GetPosition() returns the value of the sensor providing feedback, which in this case
		//  would be the Quadrature Encoder
		motors[FRONT_RIGHT]->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
		motors[FRONT_LEFT]->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);

		motors[FRONT_RIGHT]->ConfigEncoderCodesPerRev(COUNT);
		motors[FRONT_LEFT]->ConfigEncoderCodesPerRev(COUNT);

		//  Updates the Encoder values quicker
		motors[FRONT_RIGHT]->SetStatusFrameRateMs(CANTalon::StatusFrameRate::StatusFrameRateQuadEncoder, 15);
		motors[FRONT_LEFT]->SetStatusFrameRateMs(CANTalon::StatusFrameRate::StatusFrameRateQuadEncoder, 15);

}

DriveTrain::~DriveTrain() {};

Kartoffeln DriveTrain::InitDefaultCommand()
{
	SetDefaultCommand(new DriveJ());
}

void DriveTrain::DriveTank(Joystick* left, Joystick* right) {
	chassis->TankDrive(left, right);
}

//  Drives the robot given the motor powers for the left and right side of the robot
void DriveTrain::DriveTank(float left, float right)
{
	left = fmax(-1, fmin(1, left));
	right = fmax(-1, fmin(1, right));

	chassis->TankDrive(left, right);
}

//  Runs only one motor given the motor power
void DriveTrain::SetMotorValue(int MotorPort, double MotorPower) {

	motors[MotorPort]->Set(MotorPower);
}


//  Runs all the motors of the drive train given the motor power
void DriveTrain::SetAllMotorValues(double motorPower) {
	motors[FRONT_LEFT]->Set(motorPower);
	motors[REAR_LEFT]->Set(motorPower);
	motors[FRONT_RIGHT]->Set(motorPower);
	motors[REAR_RIGHT]->Set(motorPower);
}

void DriveTrain::RotateTank(float power)
{
	chassis->TankDrive(power, -power);
}

void DriveTrain::SetSafetyEnabled(bool enabled)
{
	chassis->SetSafetyEnabled(enabled);
}

void DriveTrain::InvertMotors()
{
	this->chassis->SetInvertedMotor(RobotDrive::kFrontLeftMotor, DRIVE_TRAIN_INVERTED);
	this->chassis->SetInvertedMotor(RobotDrive::kRearLeftMotor, DRIVE_TRAIN_INVERTED);
	this->chassis->SetInvertedMotor(RobotDrive::kFrontRightMotor, DRIVE_TRAIN_INVERTED);
	this->chassis->SetInvertedMotor(RobotDrive::kRearRightMotor, DRIVE_TRAIN_INVERTED);
}

//  Can change between brake and coast mode for all the motors of the drive train
void DriveTrain::SetNeutralMode(bool coast)
{
	//  If you input into this function false, mode will equal brake mode
	//  If you input true into this function, mode will equal coast mode
	CANTalon::NeutralMode mode = (coast == COAST) ? CANTalon::NeutralMode::kNeutralMode_Coast : CANTalon::NeutralMode::kNeutralMode_Brake;
	for (int i = 0; i < NUM_MOTORS; i++) {
		motors[i]->ConfigNeutralMode(mode);
	}
}

//  Zeroes the encoder given the motorIndex of the motor that attaches to the Talon
void DriveTrain::ZeroEncoder(int motorIndex) {
	motors[motorIndex]->SetPosition(0);
}

//  Gets the encoder position of the encoder hooked up to the motor Index inputed into this function
int DriveTrain::GetEncoderPosition(int motorIndex) {
	int value = motors[motorIndex]->GetEncPosition();
	std::cout << "Encoder: " << value << std::endl;
	return value;
}

//  Returns how many inches the drive train has traveled from the encoder count value
double DriveTrain::GetDistanceInches(int motorIndex) {

	int encoderPosition = GetEncoderPosition(motorIndex);
	double REVS = ((double)encoderPosition/QUADRATURE_COUNT);
	double distanceTraveled = REVS * GEAR_RATIO * CIRCUMFERENCE_OF_WHEEL;
	return distanceTraveled;
}

//  Returns the desired encoder position in order to turn the specified angle
int DriveTrain::GetEncoderPositionToTurnAngle(int angle) {
	float distanceToTravel = (CIRCUMFERENCE_OF_TURNING_ROBOT * angle)/(360.0f);
	float rotationsToSpin = (distanceToTravel/CIRCUMFERENCE_OF_WHEEL);
	int encoderPosition = (int) round(rotationsToSpin * COUNT);
	return encoderPosition * (1 / GEAR_RATIO);
}

/*
 * PIDLogging.cpp
 *
 *  Created on: Jan 23, 2016
 *      Author: conne_000
 */

#include "PIDLogging.h"
#include <sstream>
#include "RobotMap.h"
#define _USE_MATH_DEFINES
#include <cmath>

PIDLogging::PIDLogging(const std::string &name, const std::string& filePath, int numMotors, double radius):
	PIDSubsystem("PIDLogging", p, i, d),
	LogData(filePath)
{
	// TODO Auto-generated constructor stub

	this->numMotors = numMotors;

	this->radius = radius;
	diameter = this->radius * 2;

	this->circumfrence = diameter * M_PI;
}

PIDLogging::~PIDLogging() {
	// TODO Auto-generated destructor stub
	for (int i = 0; i < numMotors; i++) {
		delete motors[i];
	}
}

//  Sets up the motors in order to use the encoders properly
void PIDLogging::SetupMotors() {
	for (int i = 0; i < this->numMotors; i++) {
		//  Sets the quadrature encoders on the driveTrain as the feedback device
		//  Setting the encoder as the feedback device opens up more functions the encoder can be used in
		//  For example, GetPosition() outputs the position of the sensor providing feedback to the Talon
		//  Which in this case would be the encoder
		motors[i]->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
		//  Configures the Count of the encoder
		motors[i]->ConfigEncoderCodesPerRev(COUNT);
		//  Updates the encoder values at a faster rate
		motors[i]->SetStatusFrameRateMs(CANTalon::StatusFrameRate::StatusFrameRateQuadEncoder, 15);

		//  Only need SetControlMode if using Get() or Set() for something other than setting the motor value
		//  motors[i]->SetControlMode(CANTalon::kSpeed);
	}
}

//  Returns the Encoder Position of the encoder hooked up to the specified Talon
int PIDLogging::GetEncoderPosition(int motorIndex) {

	//  This value is equal to the QUADRATURE_COUNT * (# of Revolutions)
	//  For example, if the encoder were to spin one full rotation, the encoder position = QUADRATURE_COUNT
	return motors[motorIndex]->GetEncPosition();
}

//  Returns the Encoder Velocity of the encoder hooked up to the specified Talon
int PIDLogging::GetEncoderVelocity(int motorIndex) {

	//  Gets the Speed Value (Encoder Ticks/.1sec.) of the Encoder
	//  The value should be Count*4 because it is a quadrature encoder
	//  This value will also be used for graphing values for PID Tuning
	return motors[motorIndex]->GetEncVel();
}

//  Zeroes the encoder of the encoder hooked up to the specified Talon
void PIDLogging::ZeroEncoder(int motorIndex) {

	//  Resets the Encoder Value to Zero
	motors[motorIndex]->SetPosition(0);
}

//  Zeroes all the encoders
void PIDLogging::ZeroAllEncoders() {
	for (int i = 0; i < numMotors; i++) {
		motors[i]->SetPosition(0);
	}
}

//  Return the Distance Traveled depending upon the encoder position
double PIDLogging::GetDistanceInches(int motorIndex) {

	int encoderPosition = GetEncoderPosition(motorIndex);
	double REVS = (encoderPosition/QUADRATURE_COUNT);
	double DISTANCE_TRAVELED = REVS * this->circumfrence;
	return DISTANCE_TRAVELED;
}

//  Gets the encoder velocity in units to work with easily
double PIDLogging::GetVelocity(int motorIndex) {

	//  GetEncVel() returns the rate at which the EncPosition() is changing over .1 seconds
	int encoderVelocity = GetEncoderVelocity(motorIndex);
	double NUM_REVS_PER_SEC = (encoderVelocity * 10)/(QUADRATURE_COUNT);
	double DISTANCE_PER_SEC = NUM_REVS_PER_SEC * circumfrence;
	return DISTANCE_PER_SEC;  //  Units: Inches per second

}

void PIDLogging::FeedbackPIDOutput(int motorIndex, double output) {
	//  PIDWrite()
	motors[motorIndex]->PIDWrite(output);

}

//  Don't use this in a command as SetPIDPreferences used this function
//  Sets the PID Values of a specific motor
void PIDLogging::UpdateMotorToReflectCurrentPIDValues(int motorIndex) {
	motors[motorIndex]->SetP(this->p);
	motors[motorIndex]->SetI(this->i);
	motors[motorIndex]->SetD(this->d);
}

//  Sets the PID Values based off of the values inputed in the preferences
void PIDLogging::SetPIDPreferences() {

	this->p = Preferences::GetInstance()->GetDouble("PValue", 1.0);
	this->i = Preferences::GetInstance()->GetDouble("IValue", 0.0);
	this->d = Preferences::GetInstance()->GetDouble("DValue", 0.0);

	//  Sets the PID Values for all of the Motors
	for (int i = 0; i < numMotors; i++)
		UpdateMotorToReflectCurrentPIDValues(i);

}

//  Will write in an open log file the headers for what is being recorded in one line
//  Headers for a table made in Excels
void PIDLogging::LogEncoderDataHeader(short int whatToLog) {
	std::stringstream data;
	//  data << this->m_name << ": " << this->p << "," << this->i << "," << this->d << '\n';

	//data << this->m_name << ": " << this->p << "," << this->i << "," << this->d << '\n';


	data << "TIME";

	if((whatToLog >> POSITION_OFFSET) & 1)
		data << ",\t" << "POSITION";
	if((whatToLog >> VELOCITY_OFFSET) & 1)
		data << ",\t" << "VELOCITY";
	if((whatToLog >> DISTANCE_OFFSET) & 1)
		data << ",\t" << "DISTANCE";
	this->WriteString(data.str());
}

//  Logs the encoder data based on either position, velocity, or distance
//  Along with time in seconds
void PIDLogging::LogEncoderData(int motorIndex, double timerValue, short int whatToLog) {

	std::stringstream data;

	timerValue = Trunc(timerValue, 4);
	data << timerValue;
	std::cout << "TIME";
	if((whatToLog >> POSITION_OFFSET) & 1) {
		data << ",\t" << this->GetEncoderPosition(motorIndex);
		std::cout << "LOGGING POSITION";
	}
	if((whatToLog >> VELOCITY_OFFSET) & 1) {
		data << ",\t" << this->GetEncoderVelocity(motorIndex);
		std::cout << "LOGGING VELOCITY";
	}
	if((whatToLog >> DISTANCE_OFFSET) & 1)
		data << ",\t" << this->GetDistanceInches(motorIndex);
	//  data << "\n";
	this->WriteString(data.str());
}

//  Changes the title of the file with the PID values you are assigning the motor
 void PIDLogging::ChangeFileNameWithPIDValues() {
	std::stringstream NameofFile;
	NameofFile << "PID:" << this->p << "," << this->i << "," << this->d << ".csv";
	ChangeFileName(NameofFile.str());
}

 //  Display the pid values in the open file in one line
void PIDLogging::DisplayPIDValuesInLogData() {
	//  In the Data Logging File that will be created, the first two lines will write the P, I, and D Values Set
	//this->OpenFile();
	std::stringstream ss1;
	ss1 << "p:" << this->p << ",\ti:" << this->i << ",\td:" << this->d << ",\t" << "VALUE(TRIM(CLEAN(B4)))";
	WriteString(ss1.str());
	WriteString("---------------------------");
}


//  Functions that are never used
void PIDLogging::SetAbsoluteTolerance(float absValue) {}
void PIDLogging::SetPercentTolerance(float percent) {}
bool PIDLogging::OnTarget() const {return true;}
double PIDLogging::PIDGet() {return 0;}
double PIDLogging::ReturnPIDInput() {return 0;}
void PIDLogging::UsePIDOutput(double output) {}
void PIDLogging::InitTable(std::shared_ptr<ITable> table) {};
std::string PIDLogging::GetSmartDashboardType() const {return "";};



/*
 * PIDLogging.cpp
 *
 *  Created on: Jan 23, 2016
 *      Author: conne_000
 */

#include "PIDLogging.h"
#include <sstream>
#include "RobotMap.h"

PIDLogging::PIDLogging(const std::string &name, const std::string& filePath, int numMotors, double radius):
	PIDSubsystem("PIDLogging", p, i, d),
	LogData(filePath)
{
	// TODO Auto-generated constructor stub

	this->numMotors = numMotors;
	this->radius = radius;
	this->circumfrence = this->radius * 3.14159;
	preference.reset(new Preferences());

	//CANTalon motorTemps[numMotors];
	//this->motors = motorTemps;
	//memcpy(this->motors, motorTemps, numMotors);
}

PIDLogging::~PIDLogging() {
	// TODO Auto-generated destructor stub
	for (int i = 0; i < numMotors; i++) {
		delete motors[i];
	}
}

void PIDLogging::SetupMotors() {
	for (int i = 0; i < this->numMotors; i++) {
		motors[i]->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
		//  Only need SetControlMode if using Get() or Set() for something other than setting the motor value
		//  motors[i]->SetControlMode(CANTalon::kPosition);
		//  motors[i]->SetPosition(0);
		//  motors[i]->SetEncPosition(0);
		motors[i]->ConfigEncoderCodesPerRev(COUNT);
		//  this->SetPIDValues(i);
		SetPIDPreferences();
	}
}

int PIDLogging::GetEncoderPosition(int motorIndex) {

	//  This value is equal to the (Count*4) * (Number of Revolutions of the Motor)
	return motors[motorIndex]->GetEncPosition();
}

int PIDLogging::GetPosition(int motorIndex) {
	return motors[motorIndex]->GetPosition();
}

int PIDLogging::GetEncoderVelocity(int motorIndex) {

	//  Gets the Speed Value (Encoder Ticks/.1sec.) of the Encoder
	//  The value should be Count*4 because it is a quadrature encoder
	//  This value will also be used for graphing values for PID Tuning
	return motors[motorIndex]->GetSpeed();
}

void PIDLogging::ZeroEncoder(int motorIndex) {

	//  Resets the Encoder Value to Zero
	motors[motorIndex]->SetPosition(0);
}

void PIDLogging::ZeroAllEncoders() {
	for (int i = 0; i < numMotors; i++) {
		motors[i]->SetPosition(0);
	}
}

double PIDLogging::GetDistance(int motorIndex) {

	int encoderPosition = GetEncoderPosition(motorIndex);
	double REVS = (encoderPosition/COUNT);
	double DISTANCE_TRAVELED = REVS * circumfrence;
	return DISTANCE_TRAVELED;
}

double PIDLogging::GetVelocity(int motorIndex) {

	int encoderVelocity = GetEncoderVelocity(motorIndex);
	double NUM_REVS_PER_SEC = (encoderVelocity * 10)/(COUNT);
	double DISTANCE_PER_SEC = NUM_REVS_PER_SEC * circumfrence;
	return DISTANCE_PER_SEC;  //  Units: Inches per second

}

void PIDLogging::FeedbackPIDOutput(int motorIndex, double output) {
	//  PIDWrite()
	motors[motorIndex]->PIDWrite(output);

}

//  Don't use this in a command as SetPIDPreferences used this function
void PIDLogging::UpdateMotorToReflectCurrentPIDValues(int motorIndex) {
	motors[motorIndex]->SetP(this->p);
	motors[motorIndex]->SetI(this->i);
	motors[motorIndex]->SetD(this->d);
}

void PIDLogging::SetPIDPreferences() {

	//  this->p = preference->GetDouble("PValue-" + this->m_name, 1.0);
	//  this->i = preference->GetDouble("IValue-" + this->m_name, 0.0);
	//  this->d = preference->GetDouble("DValue-" + this->m_name, 0.0);

	if (shooterBool) {
		this->p = preference->GetDouble("ShooterPValue", 1.0);
		this->i = preference->GetDouble("ShooterIValue", 0.0);
		this->d = preference->GetDouble("ShooterDValue", 0.0);
	}
	if (driveTrainBool) {
		this->p = preference->GetDouble("DriveTrainPValue", 1.0);
		this->i = preference->GetDouble("DriveTrainIValue", 0.0);
		this->d = preference->GetDouble("DriveTrainDValue", 0.0);

	}




	for (int i = 0; i < numMotors; i++)
		UpdateMotorToReflectCurrentPIDValues(i);

}

void PIDLogging::BasedSubsytemCreateFileNameWithPID(std::string Variable) {
	std::stringstream NameofFile;
	NameofFile << this->m_name << "-" << Variable << "-" << this->p << "-" << this->i << "-" << this->d;
	ChangeFileName(NameofFile.str());
}

void PIDLogging::LogTwoEncoderValues(int motorIndex, double timerValue, double dataOne, double dataTwo) {
	//  int encoderPosition = this->GetEncoderPosition(motorIndex);
	//  int encoderGet = this->GetPosition(motorIndex);

	std::cout << "LOGGING THINGS!";
	std::stringstream data;
	timerValue = Trunc(timerValue, 4);
	data << timerValue << "," << dataOne << "," << dataTwo << "\n";
	this->WriteString(data.str());
}

void PIDLogging::LogOneEncoderValue(int motorIndex, double timerValue, double dataOne) {

	std::cout << "LOGGING THINGS!";
	std::stringstream logger;
	timerValue = Trunc(timerValue, 4);
	logger << timerValue << ",\t" << dataOne  << "\n";
	this->WriteString(logger.str());
}

void PIDLogging::LogEncoderDataHeader(short int whatToLog) {
	std::stringstream data;
	data << "TIME";

	if((whatToLog >> POSITION_OFFSET) & 1)
		data << ",\t" << "POSITION";
	if((whatToLog >> VELOCITY_OFFSET) & 1)
		data << "\t" << "VELOCITY";
	if((whatToLog >> DISTANCE_OFFSET) & 1)
		data << "\t" "DISTANCE";
}

void PIDLogging::DisplayPIDValuesInLogData() {
	//  In the Data Logging File that will be created, the first two lines will write the P, I, and D Values Set
	this->OpenFile();
	std::stringstream ss1;
	ss1 << this->p << "," << this->i << "," << this->d;
	WriteString(ss1.str());
	WriteString("---------------------------");
}

void PIDLogging::LogEncoderData(int motorIndex, double timerValue, short int whatToLog) {
	std::cout << "NEW LOGGING!";
	std::stringstream data;
	timerValue = Trunc(timerValue, 4);
	data << timerValue;

	if((whatToLog >> POSITION_OFFSET) & 1)
		data << ",\t" << this->GetEncoderPosition(motorIndex);
	if((whatToLog >> VELOCITY_OFFSET) & 1)
		data << "\t" << this->GetEncoderVelocity(motorIndex);
	if((whatToLog >> DISTANCE_OFFSET) & 1)
		data << "\t" << this->GetDistance(motorIndex);
	data << "\n";

}


void PIDLogging::SetAbsoluteTolerance(float absValue) {}
void PIDLogging::SetPercentTolerance(float percent) {}
bool PIDLogging::OnTarget() const {return true;}
double PIDLogging::PIDGet() {return 0;}
double PIDLogging::ReturnPIDInput() {return 0;}
void PIDLogging::UsePIDOutput(double output) {}
void PIDLogging::InitTable(std::shared_ptr<ITable> table) {};
std::string PIDLogging::GetSmartDashboardType() const {return "";};



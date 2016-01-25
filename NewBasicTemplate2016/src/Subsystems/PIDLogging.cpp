/*
 * PIDLogging.cpp
 *
 *  Created on: Jan 23, 2016
 *      Author: conne_000
 */

#include "PIDLogging.h"
#include <sstream>

PIDLogging::PIDLogging(const std::string &name, const std::string& filePath, double p, double i, double d, int numMotors, double radius):
	PIDSubsystem("PIDLogging", p, i, d),
	LogData(filePath)
{
	// TODO Auto-generated constructor stub

	this->numMotors = numMotors;
	this->radius = radius;
	this->circumfrence = this->radius * 3.14159;
	this->p = p, this->i = i, this->d = d;

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
		motors[i]->SetControlMode(CANTalon::kPosition);
		//  motors[i]->SetPosition(0);
		//  motors[i]->SetEncPosition(0);
		motors[i]->ConfigEncoderCodesPerRev(COUNT);
		this->SetPIDValues(i);
	}
}

int PIDLogging::GetEncoderPosition(int motorIndex) {

	//  This value is equal to the (Count*4) * (Number of Revolutions of the Motor)
	return motors[motorIndex]->GetEncPosition();
}

int PIDLogging::GetEncoder(int motorIndex) {
	return motors[motorIndex]->Get();
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

void PIDLogging::SetPIDValues(int motorIndex) {
	motors[motorIndex]->SetP(this->p);
	motors[motorIndex]->SetI(this->i);
	motors[motorIndex]->SetD(this->d);
}

void PIDLogging::LogEncoderData(int motorIndex, double timerValue) {
	int encoderPosition = this->GetEncoderPosition(motorIndex);
	int encoderGet = this->GetEncoder(motorIndex);

	std::cout << "LOGGING THINGS!";
	std::stringstream data;
	data << timerValue << ",\t" << encoderPosition << ",\t" << encoderGet;
	this->WriteString(data.str());
}

void PIDLogging::PIDWrite(float output) {}
void PIDLogging::SetAbsoluteTolerance(float absValue) {}
void PIDLogging::SetPercentTolerance(float percent) {}
bool PIDLogging::OnTarget() const {return true;}
double PIDLogging::PIDGet() {return 0;}
double PIDLogging::ReturnPIDInput() {return 0;}
void PIDLogging::UsePIDOutput(double output) {}
void PIDLogging::InitTable(std::shared_ptr<ITable> table) {};
std::string PIDLogging::GetSmartDashboardType() const {return "";};



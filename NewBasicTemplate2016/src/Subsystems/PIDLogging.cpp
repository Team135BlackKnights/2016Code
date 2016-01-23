/*
 * PIDLogging.cpp
 *
 *  Created on: Jan 23, 2016
 *      Author: conne_000
 */

#include <Subsystems/PIDLogging.h>

PIDLogging::PIDLogging(const std::string &name, const std::string& filePath, double p, double i, double d, int numMotors, double radius):
	PIDSubsystem("PIDLogging", p, i, d),
	LogData(filePath)
{
	// TODO Auto-generated constructor stub

	this->numMotors = numMotors;
	this->radius = radius;
	this->circumfrence = this->radius * 3.14159;
	this->p = p, this->i = i, this->d = d;

	motors = std::shared_ptr<CANTalon>[numMotors];
}

PIDLogging::~PIDLogging() {
	// TODO Auto-generated destructor stub
	for (int i = 0; i < numMotors; i++) {
		motors[i].reset();
	}
}

void PIDLogging::SetupMotors() {
	for (int i = 0; i < this->numMotors; i++) {
		motors[i]->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
		//  motors[i]->SetControlMode(CANTalon::kPosition);
		//  motors[i]->SetPosition(0);
		//  motors[i]->SetEncPosition(0);
		motors[i]->ConfigEncoderCodesPerRev(COUNT);
		this->SetPIDValues(i);
	}
}

int PIDLogging::GetEncoderPosition(int motorIndex) {

	//  This value is equal to the (Count*4) * (Number of Revolutions of the Motor)
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

void PIDLogging::SetPIDValues(int motorIndex) {
	motors[i]->SetP(this->p);
	motors[i]->SetI(this->i);
	motors[i]->SetD(this->d);
}

void PIDLogging::LogEncoderData(int motorIndex, double time) {
	double encoderValue = this->GetEncoderVelocity(motorIndex);

	// current date/time based on current system
	time_t now = time(0);
	tm *ltm = localtime(&now);

	// print various components of tm structure.
	std::string year = (std::string)(int)(1900 + ltm->tm_year);
	std::string month = (std::string)(int)(1 + ltm->tm_mon);
	std::string day = (std::string)(int)(ltm->tm_mday);
	std::string hour = (std::string)(int)(ltm->tm_hour);
	std::string min = (std::string)(int)(ltm->tm_min);
	std::string sec = (std::string)(int)(ltm->tm_sec);
	std::string fileName = month + "-" + day + "-" + year + " " + hour + ":" + min + ":" + sec;
	this->WriteDoubles(fileName, this->p, this->i, this->d);
	this->WriteString(fileName, "---------------------------");
	this->WriteDoubles(fileName, time, motorIndex);
}



/*
 * PIDLogging.h
 *
 *  Created on: Jan 23, 2016
 *      Author: conne_000
 */

#ifndef SRC_SUBSYSTEMS_PIDLOGGING_H_
#define SRC_SUBSYSTEMS_PIDLOGGING_H_

#include <Commands/PIDSubsystem.h>

virtual class PIDLogging: public PIDSubsystem, LogData {
public:
	PIDLogging(const std::string&, const std::string&, double, double, double, int, double);
	virtual ~PIDLogging();

private:
	std::shared_ptr<CANTalon> motors[]; //Array of motors that you want to read encoder data from

	int numMotors;
	static const int COUNT = 64;
	//int quadratureCOUNT;

	double radius; //  In inches, assuming ALL wheels have the same radius

	double circumfrence;

	double p, i, d;

public:
	virtual void SetupMotors();
	virtual int GetEncoderPosition(int);
	virtual int GetEncoderVelocity(int);
	virtual void ZeroEncoder(int);
	virtual void ZeroAllEncoders();
	virtual double GetDistance(int);
	virtual double GetVelocity(int);
	virtual void LogEncoderData(int, double);

	virtual void FeedbackPIDOutput(int, double);
	virtual void SetPIDValues(int);
};

#endif /* SRC_SUBSYSTEMS_PIDLOGGING_H_ */

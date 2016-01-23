/*
 * PIDLogging.h
 *
 *  Created on: Jan 23, 2016
 *      Author: conne_000
 */

#ifndef SRC_SUBSYSTEMS_PIDLOGGING_H_
#define SRC_SUBSYSTEMS_PIDLOGGING_H_

#include <Commands/PIDSubsystem.h>
#include "LogData.h"

class PIDLogging: public PIDSubsystem, public LogData {
public:
	PIDLogging(const std::string&, const std::string&, double, double, double, int, double);
	virtual ~PIDLogging();

protected:
	//std::shared_ptr<CANTalon> motors[]; //Array of motors that you want to read encoder data from
	CANTalon* motors[10];

	int numMotors;
	static const int COUNT = 64;
	//int quadratureCOUNT;

	double radius; //  In inches, assuming ALL wheels have the same radius

	double circumfrence;

public:
	double p, i, d;

public:
	void SetupMotors();
	int GetEncoderPosition(int);
	int GetEncoderVelocity(int);
	void ZeroEncoder(int);
	void ZeroAllEncoders();
	double GetDistance(int);
	double GetVelocity(int);
	void LogEncoderData(int, double);

	void FeedbackPIDOutput(int, double);
	void SetPIDValues(int);


	// PIDOutput interface
	void PIDWrite(float output);

	// PIDSource interface
	double PIDGet();

	void SetAbsoluteTolerance(float absValue);
	void SetPercentTolerance(float percent);
	bool OnTarget() const;

	protected:

	double ReturnPIDInput();
	void UsePIDOutput(double output);

	public:
	void InitTable(std::shared_ptr<ITable> table);
	std::string GetSmartDashboardType() const;
};

#endif /* SRC_SUBSYSTEMS_PIDLOGGING_H_ */

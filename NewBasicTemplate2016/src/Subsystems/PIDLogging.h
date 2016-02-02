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
	PIDLogging(const std::string&, const std::string&, int, double);
	virtual ~PIDLogging();

protected:
	//  std::shared_ptr<CANTalon> motors[10]; //Array of motors that you want to read encoder data from
	CANTalon* motors[10];

	int numMotors;
	static const int COUNT = 64;
	//int quadratureCOUNT;

	double radius; //  In inches, assuming ALL wheels have the same radius

	double circumfrence;

public:
	static const short int POSITION = 			0b001;
	static const int POSITION_OFFSET = 			0;
	static const short int VELOCITY = 			0b010;
	static const int VELOCITY_OFFSET = 			1;
	static const short int DISTANCE = 			0b100;
	static const int DISTANCE_OFFSET = 			2;

	double p,
		   i,
		   d;

private:
	void UpdateMotorToReflectCurrentPIDValues(int);

public:
	void SetupMotors();
	int GetEncoderPosition(int);
	int GetPosition(int);
	int GetEncoderVelocity(int);
	void ZeroEncoder(int);
	void ZeroAllEncoders();
	double GetDistance(int);
	double GetVelocity(int);

	void LogTwoEncoderValues(int, double, double, double);
	void LogOneEncoderValue(int, double, double);

	void LogEncoderData(int, double, short int);
	void LogEncoderDataHeader(short int);

	void FeedbackPIDOutput(int, double);
	//  void SetPIDValues(int);
	void SetPIDPreferences();
	//  bool shooterBool = false;
	//  bool driveTrainBool = false;
	void ChangeFileNameWithSubsystemName();
	void DisplayPIDValuesInLogData();


	//  The functions below are not defined in the .cpp file and are not used
	// PIDOutput interface
	void PIDWriteValueForFeedback(int, double);

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

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

class PIDLogging: public PIDSubsystem, public LogData
{
public:
	PIDLogging(const std::string&, const std::string&, int, double);
	virtual ~PIDLogging();

protected:
	// Declares 10 Talon Motors 0-9
	CANTalon* motors[10];

	int numMotors;

	//  Encoder Count for all the encoders except for the one on the shooter (Magnetic) and the arm (256 Count)
	static const int COUNT = 64;
	static const int QUADRATURE_COUNT = (COUNT * 4);

	double radius; //  In inches

	double diameter;

	double circumfrence;

public:
	double p,
		   i,
		   d;

private:
	void UpdateMotorToReflectCurrentPIDValues(int);

public:
	//  Binary Variables from Eddie
	static const short int POSITION = 			0b001;
	static const int POSITION_OFFSET = 			0;
	static const short int VELOCITY = 			0b010;
	static const int VELOCITY_OFFSET = 			1;
	static const short int DISTANCE = 			0b100;
	static const int DISTANCE_OFFSET = 			2;

	//  Sets up the motors for the purpose of the encoders
	void SetupMotors();
	//  Encoder Functions
	int GetEncoderPosition(int);
	int GetEncoderVelocity(int);
	void ZeroEncoder(int);
	void ZeroAllEncoders();
	double GetDistanceInches(int);
	double GetVelocity(int);

	void FeedbackPIDOutput(int, double);

	//  Setting the P,I, and D Values based on the values the user inputs in the Preferences
	void SetPIDPreferences();

	void ChangeFileNameWithPIDValues();
	void DisplayPIDValuesInLogData();

	void LogEncoderData(int, double, short int);
	void LogEncoderDataHeader(short int);


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

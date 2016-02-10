#ifndef SerialCommunication_H
#define SerialCommunication_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class SerialCommunication: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	static const int BAUD_RATE = 9600;
	static const int COUNT = 1;
	static const int DATA_BITS = 8;
	//  static const int TIMEOUT_TIME = ((COUNT * DATA_BITS)/BAUD_RATE);
	static const int TIMEOUT_TIME = .1;

	//  Number of Values that are going to be combined into a CSV (Comma Separated Value)
	static const int numberOfValues = 2;

	static const int LEFT_SONAR_VALUE = 0;
	static const int RIGHT_SONAR_VALUE = 1;

	//  std::unique<SerialPort> serialPort;
	SerialPort *serialPort;

	char* readings;

	char* data[numberOfValues];

	double readData;

public:
	SerialCommunication();
	void InitDefaultCommand();
	double StopSerialCommunicationAndReturnLastValue(int);
	double GetSerialValues(int);
};

#endif

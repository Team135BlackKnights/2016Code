#ifndef SerialCommunication_H
#define SerialCommunication_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class SerialCommunication: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	static const int BAUD_RATE = 57600;
	static const int COUNT = 3;
	static const int DATA_BITS = 8;
	//  static const int TIMEOUT_TIME = ((COUNT * DATA_BITS)/BAUD_RATE);
	static const int TIMEOUT_TIME = .1;

	//  Number of Values that are going to be combined into a CSV (Comma Separated Value)
	static const int numberOfValues = 3;

	//  std::unique<SerialPort> serialPort;
	SerialPort *serialPort;

	char* readings[numberOfValues];

	char* data[numberOfValues];

	double readData;

public:
	SerialCommunication();
	void InitDefaultCommand();
	double StopSerialCommunicationAndReturnLastValue(int);
	double GetSerialValues(int);


	static const int LEFT_SONAR_VALUE = 0;
	static const int RIGHT_SONAR_VALUE = 1;
	static const int LIGHT_SENSOR_VALUE = 2;
};

#endif

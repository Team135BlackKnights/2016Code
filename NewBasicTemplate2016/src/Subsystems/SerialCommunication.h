#ifndef SerialCommunication_H
#define SerialCommunication_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class SerialCommunication: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	static const int BAUD_RATE = 115200;
	static const int COUNT = 3;
	static const int DATA_BITS = 100;
	//  static const int TIMEOUT_TIME = ((COUNT * DATA_BITS)/BAUD_RATE);
	const float TIMEOUT_TIME = .15f;

	//  Number of Values that are going to be combined into a CSV (Comma Separated Value)
	static const int numberOfValues = 3;

	//  std::unique<SerialPort> serialPort;
	SerialPort *serialPort;

	char* readings[numberOfValues];

	double data[numberOfValues];

	char*  buffer;

	//  Values Still To Be Determined
	double leftSonarBarrierDistance = 20,
		   rightSonarBarrierDistance = 20,
		   lightValue = 10;


public:

	SerialCommunication();
	void InitDefaultCommand();
	void StopSerialCommunicationAndReturnLastValue();
	double GetSerialValues(int);
	void ReadSerialValues();

	bool OverDefense();


	static const int LEFT_SONAR_VALUE = 0;
	static const int RIGHT_SONAR_VALUE = 1;
	static const int LIGHT_SENSOR_VALUE = 2;
};

#endif

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

	int bytesReceived;

	int isCrooked;


public:
	SerialCommunication();
	void InitDefaultCommand();
	void StopSerialCommunicationAndReturnLastValue();
	double GetSerialValues(int);
	void ReadSerialValues();
	int IsCrookedAndOffCenter();


	enum SENSOR_VALUES {
		LEFT_SONAR_VALUE = 0,
		RIGHT_SONAR_VALUE = 1,
		LIGHT_SENSOR_VALUE = 2,
	};


	enum DIRECTION {
			NOT_CROOKED = 1,
			CROOKED_LEFT = 2,
			CROOKED_RIGHT = 3
		};


};

#endif

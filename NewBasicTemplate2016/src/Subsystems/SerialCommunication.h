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
	static const int COUNT = 10;
	static const int DATA_BITS = 8;
	//  static const int TIMEOUT_TIME = ((COUNT * DATA_BITS)/BAUD_RATE);
	static const int TIMEOUT_TIME = .15;

	//  std::unique<SerialPort> serialPort;
	SerialPort *serialPort;

	char* data[COUNT];

	double doubleData;

public:
	SerialCommunication();
	void InitDefaultCommand();
	void ReadSerialValues();
	void StopSerialCommunication();
	double GetSerialValues();
};

#endif

#ifndef SerialCommunication_H
#define SerialCommunication_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class SerialCommunication: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::unique_ptr<SerialPort> serialPort;

	static const int BYTES_TO_WRITE = 5;
public:
	SerialCommunication();
	void InitDefaultCommand();
	void SendSerialShooterTrackerValue(double);
};

#endif

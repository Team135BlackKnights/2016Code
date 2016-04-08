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

	int bytesToWrite;
	//char *buffer;
public:
	SerialCommunication();
	void InitDefaultCommand();
	void SendSerialShooterTrackerValue(double);
	void SendSonarDistanceValue(float);
};

#endif

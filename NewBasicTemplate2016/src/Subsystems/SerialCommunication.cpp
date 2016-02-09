#include "SerialCommunication.h"
#include "../RobotMap.h"

SerialCommunication::SerialCommunication() :
		Subsystem("ExampleSubsystem")
{

	//  serialPort.reset(new SerialPort);
	serialPort = new SerialPort(BAUD_RATE, SerialPort::kMXP, DATA_BITS);
	serialPort->SetReadBufferSize(COUNT);
	serialPort->SetTimeout(TIMEOUT_TIME);
	data[COUNT] = new char;
	doubleData = 0;
}

void SerialCommunication::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void SerialCommunication::ReadSerialValues() {
	if (serialPort->GetBytesReceived() > 0) {
		for (int i = 0; i < COUNT; i++) {
			serialPort->Read(data[i], COUNT);
			std::cout  <<  data[i] << std::endl;
		}
	}
}
double SerialCommunication::GetSerialValues() {
	if (serialPort->GetBytesReceived() > 0) {
		for (int i = 0; i < COUNT; i++) {
			serialPort->Read(data[i], COUNT);
			//  Need to convert from string to double
			doubleData = strtod(data[i], NULL);
		}
	}
	return doubleData;
}

void SerialCommunication::StopSerialCommunication() {
	serialPort->EnableTermination('\n');
	if (serialPort->GetBytesReceived() > 0) {
		for (int i = 0; i < COUNT; i++) {
			serialPort->Read(data[i], COUNT);
			if (data[i] > 0) {
				std::cout  <<  data[i] << std::endl;
			}
		}
	}
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

#include "SerialCommunication.h"
#include "../RobotMap.h"

SerialCommunication::SerialCommunication() :
		Subsystem("ExampleSubsystem")
{

	//  serialPort.reset(new SerialPort);
	serialPort = new SerialPort(BAUD_RATE, SerialPort::kMXP, DATA_BITS);
	serialPort->SetReadBufferSize(COUNT);
	serialPort->SetTimeout(TIMEOUT_TIME);

	readings[numberOfValues] = new char;

	data[numberOfValues] = new char;

	readData = 0;
}

void SerialCommunication::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

//  LEFT_SONAR_VALUE = 0;
//  RIGHT_SONAR_VALUE = 1;
//  LIGHT_SENSOR_VALUE = 2;
double SerialCommunication::GetSerialValues(int typeOfValue) {
	if (serialPort->GetBytesReceived() >= numberOfValues) {
		for (int j = 0; j < numberOfValues; j++) {
			serialPort->Read(readings[j], COUNT);
		}
		readData = strtod(readings[typeOfValue], NULL);
		return readData;
	}
	else {
		return 0;
	}

	/*if (serialPort->GetBytesReceived() > 0) {
		serialPort->Read(readings, COUNT);
		for (int j = 0; j < numberOfValues; j++) {
			data[j] = strtok(readings, ",");
		}
		readData = strtod(data[typeOfValue], NULL);
		return readData;
	}
	else {
		return 0;
	}*/

	/* if (serialPort->GetBytesReceived() > 0) {
		for (int i = 0; i < COUNT; i++) {
			serialPort->Read(readings[i], COUNT);
			for (int j = 0; j < numberOfValues; j++) {
				data[j] = strtok(readings[i], ",");
			}
			std::cout << data[typeOfValue] << std::endl;
			readData = strtod(data[typeOfValue], NULL);
		}
	}
	return readData; */
}

double SerialCommunication::StopSerialCommunicationAndReturnLastValue(int typeOfValue) {
	serialPort->EnableTermination('\n');

	if (serialPort->GetBytesReceived() >= (typeOfValue + 1)) {
		for (int j = 0; j < numberOfValues; j++) {
			serialPort->Read(readings[j], COUNT);
		}
		readData = strtod(readings[typeOfValue], NULL);
		return readData;
	}
	else {
		return 0;
	}

	/*if (serialPort->GetBytesReceived() > 0) {
		serialPort->Read(readings, COUNT);
		for (int j = 0; j < numberOfValues; j++) {
			data[j] = strtok(readings, ",");
		}
		readData = strtod(data[typeOfValue], NULL);
		return readData;
	}
	else {
		return 0;
	} */

	/*if (serialPort->GetBytesReceived() > 0) {
		for (int i = 0; i < COUNT; i++) {
			serialPort->Read(readings[i], COUNT);
			if (readings[i] > 0) {
				std::cout  <<  readings[i] << std::endl;
			}
		}
	} */
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

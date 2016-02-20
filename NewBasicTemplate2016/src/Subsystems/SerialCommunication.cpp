#include "SerialCommunication.h"
#include "../RobotMap.h"
#include "Commands/UltrasonicTesting.h"
#include <sstream>

SerialCommunication::SerialCommunication() :
		Subsystem("SerialCommunication")
{

	//  serialPort.reset(new SerialPort);
	//serialPort->Reset();
	serialPort = new SerialPort(BAUD_RATE, SerialPort::Port::kMXP);
	//serialPort->SetReadBufferSize(10);

	serialPort->EnableTermination('\n');
	serialPort->SetTimeout(10);
	//serialPort->SetReadBufferSize(16);

	buffer = new char('\a');
}

void SerialCommunication::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new UltrasonicTesting());
}

//  LEFT_SONAR_VALUE = 0;
//  RIGHT_SONAR_VALUE = 1;
//  LIGHT_SENSOR_VALUE = 2;
void SerialCommunication::ReadSerialValues() {
	if (serialPort->GetBytesReceived() == 0) {
		std::cout << -1;
		return;
	}
	while (serialPort->GetBytesReceived() > 0) {
		std::cout << "bad";
		buffer = new char('\a');
		int index = -1;
		serialPort->Read(buffer, 8);
		if (buffer[0] == 'L') {
			index = LEFT_SONAR_VALUE;
		}
		else if (buffer[0] == 'R') {
			index = RIGHT_SONAR_VALUE;
		}
		else if (buffer[0] == 'B') {
			index = LIGHT_SENSOR_VALUE;
		}
		else
			continue;


		//std::cout << index;
		std::stringstream dataThing;
		int length = strlen(buffer);
		for (int i = 1; i < length; ++i)
		{
			dataThing << buffer[i];
			//std::cout << dataThing << std::endl;
		}
		data[index] = strtod(dataThing.str().c_str(), NULL);
	}
	/*
	char* newBuffer = strtok(buffer, ",");
	int j = 0;
	while (newBuffer) {
		std::cout << newBuffer << std::endl;
		readings[j] = strtok(NULL, ",");
		j++;
	}

	for (int i = 0; i < numberOfValues; i++) {
		data[i] = strtod(readings[i], NULL);
	}
	*/

	/*
	if (serialPort->GetBytesReceived() >= numberOfValues) {
		for (int j = 0; j < numberOfValues; j++) {
			serialPort->Read(readings[j], 8);
		}
		dat = strtod(readings[typeOfValue], NULL);
		return readData;
	}
	else {
		return 0;
	} */

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

double SerialCommunication::GetSerialValues(int TypeOfValue) {
	return data[TypeOfValue];
	/*
	if (serialPort->GetBytesReceived() == 0)
			return 0;

		while (serialPort->GetBytesReceived() >= 0) {
			serialPort->Read(buffer, 8);
		}
			readings[0] = strtok(buffer, ",");
			for (int j = 1; j < numberOfValues; j++) {
				readings[j] = strtok(NULL, ",");
			}
			for (int i = 0; i < numberOfValues; i++) {
				data[i] = strtod(readings[i], NULL);
			}
		return data[TypeOfValue];
	//  ReadSerialValues();
	//  return data[TypeOfValue];
	 */

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

bool SerialCommunication::OverDefense(int typeOfMethod) {
	switch (typeOfMethod) {
	case CASE_LIGHT:
		if (data[LIGHT_SENSOR_VALUE] > lightValue) {
			return true;
		}
		else {
			return false;
		}
	break;

	case CASE_LEFT_AND_LIGHT:
		if (data[LEFT_SONAR_VALUE] > leftSonarBarrierDistance && data[LIGHT_SENSOR_VALUE] > lightValue) {
			return true;
		}
		else {
			return false;
		}
	break;

	case CASE_RIGHT_AND_LIGHT:
		if (data[RIGHT_SONAR_VALUE] > rightSonarBarrierDistance && data[LIGHT_SENSOR_VALUE] > lightValue) {
			return true;
		}
		else {
			return false;
		}
	break;

	case CASE_LEFT_RIGHT_AND_LIGHT:
		if (data[LEFT_SONAR_VALUE] > leftSonarBarrierDistance && data[RIGHT_SONAR_VALUE] > rightSonarBarrierDistance && data[LIGHT_SENSOR_VALUE] > lightValue) {
			return true;
		}
		else {
			return false;
		}
	break;

	default:
		return false;
	break;
	}
}


//  LEFT_SONAR_VALUE = 0;
//  RIGHT_SONAR_VALUE = 1;
//  LIGHT_SENSOR_VALUE = 2;


// Put methods for controlling this subsystem
// here. Call these from Commands.

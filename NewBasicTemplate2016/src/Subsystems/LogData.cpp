#include "LogData.h"
#include "../RobotMap.h"
#include<stdarg.h>

LogData::LogData(std::string filePath)
{
	this->filePath = filePath;
}

void LogData::WriteString(std::string fileName, std::string data) {
	if (!logFile.is_open()) {
		logFile.open(this->filePath + fileName, std::fstream::out);
	}
	logFile << data << "\n";
}

void LogData::WriteDoubles(std::string fileName, double values[]) {
	if (logFile.is_open() == false) {
		logFile.open(filePath + fileName, std::fstream::out);
	}
	bool comma = false;
	int size = sizeof(values)/sizeof(values[0]);
	for (int i = 0; i < size; i++) {
		double value = values[i];
		if (comma)
			logFile << ", ";
		else
			comma = true;
		logFile << value;
	}
	logFile << "\n";
}

void LogData::ChangeFilePath(std::string path) {
	this->filePath = path;
}

void LogData::CloseFile() {
	if (logFile.is_open() == true) {
		logFile.flush();
	}

	logFile.close();
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

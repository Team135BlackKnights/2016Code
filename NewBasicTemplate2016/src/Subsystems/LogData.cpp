#include "LogData.h"
#include "../RobotMap.h"
#include<stdarg.h>

LogData::LogData(std::string filePath)
{
	this->filePath = filePath;
	this->fileName = "";
}

void LogData::WriteString(std::string data, std::string path, std::string name) {
	if (path == "") path = this->filePath;
	if (name == "") name = this->fileName;

	if (path == "" || name == "")
		return perror("INVALID FILE NAME OR FILE PATH");

	if (!logFile.is_open()) {
		logFile.open(path + name, std::fstream::out);
	}
	logFile << data << "\n";
}

/*
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
*/

void LogData::ChangeFilePath(std::string path) {
	this->filePath = path;
}

void LogData::ChangeFileName(std::string name) {
	this->fileName = name;
}

void LogData::CloseFile() {
	if (logFile.is_open() == true) {
		logFile.flush();
	}

	logFile.close();
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

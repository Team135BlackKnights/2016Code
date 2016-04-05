#include "LogData.h"
#include "../RobotMap.h"
#include<stdarg.h>
#include <sstream>

LogData::LogData(std::string filePath)
{
	this->filePath = filePath;
	this->fileName = "";
}

void LogData::WriteString(std::string data) {
	this->OpenFile();
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

void LogData::BasedTimeCreateFileName() {
	std::stringstream fileName;
	// current date/time based on current system
	time_t now = time(0);
	tm *ltm = localtime(&now);
	fileName <<  ZeroifyNumber(1 + ltm->tm_mon, 2) << "-" << ZeroifyNumber(ltm->tm_mday, 2) << "-" << ltm->tm_year - 100 << " " <<
			ZeroifyNumber(ltm->tm_hour, 2) << ":" << ZeroifyNumber(ltm->tm_min, 2) << ":" << ZeroifyNumber(ltm->tm_sec, 2) << ".csv";
	ChangeFileName(fileName.str());
}

void LogData::CloseFile() {
	if (logFile.is_open() == true) {
		logFile.flush();
	}

	logFile.close();
}

void LogData::OpenFile() {
	//if (path == "") path = this->filePath;
	//if (name == "") name = this->fileName;

	if (this->filePath == "" || this->fileName == "")
		return perror("INVALID FILE NAME OR FILE PATH");

	if (!logFile.is_open()) {
		logFile.open(this->filePath + this->fileName, std::fstream::out);
	}
}

std::string LogData::ZeroifyNumber(int number, int digits) {
    std::stringstream num;
	for (int i = 0; i < digits; i++) {
		if (number < pow(10, i)) {
			num << "0";
		}
	}
	num << number;
	return num.str();
}

void LogData::LogShooterTrackerValueHeader() {
	std::stringstream data;

	data << "TIME" << "," << "SHOOTER SPEED" << "," << "VALUE(TRIM(CLEAN()))" << "\n";

	this->WriteString(data.str());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

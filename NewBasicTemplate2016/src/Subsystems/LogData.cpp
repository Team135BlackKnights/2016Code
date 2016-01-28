#include "LogData.h"
#include "../RobotMap.h"
#include<stdarg.h>

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
	fileName <<  1 + ltm->tm_mon << "-" << ltm->tm_mday << "-" << ltm->tm_year - 100 << " " <<
				ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec;
	ChangeFileName(fileName.str());
}

void LogData::DisplayPIDValuesInLogData(double p, double i, double d) {
	//  In the Data Logging File that will be created, the first two lines will write the P, I, and D Values Set
	this->OpenFile();
	std::stringstream ss1;
	ss1 << p << "," << i << "," << d;
	WriteString(ss1.str());
	WriteString("---------------------------");
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


// Put methods for controlling this subsystem
// here. Call these from Commands.

#include "LogData.h"
#include "../RobotMap.h"
#include<stdarg.h>
#include <sstream>


//  When you are logging data, you first have to declare the file path and file name
//  The File Path is already inputed in CommandBase.cpp
//  The File Name can either be named based off of time or the p,i, and d values

//  You also have to open the file before you send data to the file
//  When you are done sending data to the file, you also have to close the file
LogData::LogData(std::string filePath)
{
	this->filePath = filePath;
	this->fileName = "";
}

//  Writes a single string in a file
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

//  Titles the File Based off of the current time
void LogData::BasedTimeCreateFileName() {
	std::stringstream fileName;
	// current date/time based on current system
	time_t now = time(0);
	tm *ltm = localtime(&now);
	fileName <<  ZeroifyNumber(1 + ltm->tm_mon, 2) << "-" << ZeroifyNumber(ltm->tm_mday, 2) << "-" << ltm->tm_year - 100 << " " <<
			ZeroifyNumber(ltm->tm_hour, 2) << ":" << ZeroifyNumber(ltm->tm_min, 2) << ":" << ZeroifyNumber(ltm->tm_sec, 2) << ".csv";
	ChangeFileName(fileName.str());
}

//  Close a file
void LogData::CloseFile() {
	if (logFile.is_open() == true) {
		logFile.flush();
	}

	logFile.close();
}

void LogData::OpenFile() {
	//if (path == "") path = this->filePath;
	//if (name == "") name = this->fileName;

	//  If you have not named the file or defined the file path
	if (this->filePath == "" || this->fileName == "")
		return perror("INVALID FILE NAME OR FILE PATH");  //  Error

	//  If the log file is not open, then open it with the specified file name
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

//  Logs three values, one for time, two for the actual data
void LogData::LogTwoEncoderValues(int motorIndex, double timerValue, double dataOne, double dataTwo) {

	std::cout << "LOGGING THINGS!";
	std::stringstream data;
	timerValue = Trunc(timerValue, 4);
	data << timerValue << "," << dataOne << "," << dataTwo << "\n";
	this->WriteString(data.str());
}

//  Logs two values, one for time, one for the actual data
void LogData::LogOneEncoderValue(int motorIndex, double timerValue, double dataOne) {

	std::cout << "LOGGING THINGS!";
	std::stringstream logger;
	timerValue = Trunc(timerValue, 4);
	logger << timerValue << "," << dataOne  << "\n";
	this->WriteString(logger.str());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

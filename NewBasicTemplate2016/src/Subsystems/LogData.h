#ifndef LogData_H
#define LogData_H

#include "WPILib.h"
#include <fstream>
#include <string>
#include "PIDLogging.h"

class LogData
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	//  Declares a variable based off of the functions of ofstream
	//  of in ofstream stands for Output File
	//  You need to make a variable of this type to send data to a file in the RoboRIO
	std::ofstream logFile;
	//  The location in which the file is stored
	std::string filePath;
	//  The name of the file
	std::string fileName;

public:
	LogData(std::string);
	void WriteString(std::string);
	//void WriteDoubles(std::string, double[]);
	void ChangeFilePath(std::string);
	void ChangeFileName(std::string);
	void BasedTimeCreateFileName();

	void CloseFile();
	void OpenFile();

	std::string ZeroifyNumber(int, int);

	void LogOneEncoderValue(int, double, double);
	void LogTwoEncoderValues(int, double, double, double);
};

#endif

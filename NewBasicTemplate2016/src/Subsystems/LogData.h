#ifndef LogData_H
#define LogData_H

#include "WPILib.h"
#include <fstream>
#include <string>

class LogData
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::ofstream logFile;
	std::string filePath;
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

	void LogShooterTrackerValueHeader();
};

#endif

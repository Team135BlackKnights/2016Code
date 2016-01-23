#ifndef LogData_H
#define LogData_H

#include "WPILib.h"
#include <fstream>

class LogData
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::ofstream logFile;
	std::string filePath;

public:
	LogData(std::string);
	void WriteString(std::string, std::string);
	void WriteDoubles(std::string, double[]);
	void ChangeFilePath(std::string);
	void CloseFile();
};

#endif

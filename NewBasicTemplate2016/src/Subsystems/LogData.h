#ifndef LogData_H
#define LogData_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <fstream>

class LogData: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::ofstream logFile;

public:
	LogData();
	void InitDefaultCommand();
	void WriteData(double, double, std::string);
	void CloseFile();
};

#endif

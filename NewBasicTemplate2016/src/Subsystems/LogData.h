#ifndef LogData_H
#define LogData_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class LogData: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	LogData();
	void InitDefaultCommand();
};

#endif

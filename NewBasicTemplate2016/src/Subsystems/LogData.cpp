#include "LogData.h"
#include "../RobotMap.h"

LogData::LogData() :
		Subsystem("ExampleSubsystem")
{

}

void LogData::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void LogData::WriteData(double dataValueOne, double dataValueTwo, std::string fileName) {
	if (logFile.is_open() == false) {
		logFile.open("/home/lvuser/" + fileName, std::fstream::out);
	}
	logFile << dataValueOne << "," << dataValueTwo << "," << "\n";
}

void LogData::CloseFile() {
	if (logFile.is_open() == true) {
		logFile.flush();
	}

	logFile.close();
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

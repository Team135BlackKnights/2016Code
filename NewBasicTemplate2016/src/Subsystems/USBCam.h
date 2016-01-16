#ifndef USBCam_H
#define USBCam_H

#include <Commands/Subsystem.h>
#include <networktables/NetworkTable.h>
#include <memory>
#include "WPILib.h"
#include <unistd.h>

class USBCam: public Subsystem
{
private:
	const char* CAMERA_NAME = "cam2";
	const char * const JAVA = "/usr/local/frc/JRE/bin/java";
	const char * const GRIP_JAR = "/home/lvuser/grip.jar";
	const char * const GRIP_PROJECT = "home/lvuser/myproject.grip";
	std::shared_ptr<NetworkTable> grip = NetworkTable::GetTable("grip");
	double targetX = 0.0;
	double targetY = 0.0;
	double targetArea = -1.0;
public:
	USBCam();
	void InitDefaultCommand();
	std::tuple<double, double, double> findBiggest();
};

#endif

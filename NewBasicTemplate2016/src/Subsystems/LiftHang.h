#ifndef LiftHang_H
#define LiftHang_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "RobotMap.h"

class LiftHang: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::unique_ptr<CANTalon> motors;

public:
	LiftHang();
	void InitDefaultCommand();
	void DriveMotor(float);
};

#endif

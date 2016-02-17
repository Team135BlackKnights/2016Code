#ifndef MotorTesting_H
#define MotorTesting_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class MotorTesting: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	std::unique_ptr<CANTalon> cantalonMotor;
	std::unique_ptr<VictorSP> victorMotor;

public:
	MotorTesting();
	void InitDefaultCommand();

	void RunTalonMotor(int, float);
	void RunVictorMotor(int, float);
};

#endif

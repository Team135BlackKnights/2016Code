#ifndef DefenseArm_H
#define DefenseArm_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DefenseArm: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::unique_ptr<CANTalon> motor;
public:
	DefenseArm();
	void InitDefaultCommand();
	void DriveMotor(float power);

	static constexpr float UP = -.4f;
	static constexpr float DOWN = -UP;
};

#endif

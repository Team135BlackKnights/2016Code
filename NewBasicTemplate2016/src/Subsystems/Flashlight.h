#ifndef Flashlight_H
#define Flashlight_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Flashlight: public Subsystem
{
private:
	std::unique_ptr<Relay> light;
	//std::unique_ptr<Solenoid> lightTest;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Flashlight();
	void InitDefaultCommand();
	void SetFlashlight(bool on);
	bool on;
};

#endif

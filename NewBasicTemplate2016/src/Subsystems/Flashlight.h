#ifndef Flashlight_H
#define Flashlight_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Flashlight: public Subsystem
{
private:
	//std::unique_ptr<Relay> light;
	//std::unique_ptr<Solenoid> lightTest;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	//Solenoid* activeSoul;
public:
	Flashlight();
	void InitDefaultCommand();
	void SetSolenoid(Solenoid* solenoid, bool power);
	void SwitchActiveSoul();
	bool on;
	//Solenoid* turnOn;
	//Solenoid* turnOff;
};

#endif

#include "Flashlight.h"
#include "../RobotMap.h"
#include "../Commands/DriveFlashlight.h"

Flashlight::Flashlight() :
		Subsystem("Flashlight")
{
		//light.reset(new Relay(2, Relay::Direction::kBothDirections));
		//lightTest.reset(new Solenoid(2));
		turnOn = new Solenoid(3);
		turnOff = new Solenoid(2);
		activeSoul = turnOff;
}

void Flashlight::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	//SetDefaultCommand(new DriveFlashlight());
}

void Flashlight::SetSolenoid(Solenoid* solenoid, bool power) {
	//if (this->on != on) {
		//SmartDashboard::PutBoolean("LIGHT", light->Get() == Relay::kForward || light->Get() == Relay::Value::kOn);
		//light->Set(this->on ? Relay::Value::kForward : Relay::Value::kReverse);
		solenoid->Set(power);
	//}
}

void Flashlight::SwitchActiveSoul() {
	on = !on;
	if (on)
		activeSoul = turnOn;
	else
		activeSoul = turnOff;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

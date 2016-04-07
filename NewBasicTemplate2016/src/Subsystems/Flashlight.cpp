#include "Flashlight.h"
#include "../RobotMap.h"
#include "../Commands/DriveFlashlight.h"

Flashlight::Flashlight() :
		Subsystem("Flashlight")
{
		light.reset(new Relay(2, Relay::Direction::kBothDirections));
		//lightTest.reset(new Solenoid(2));
		turnOn.reset(new DigitalOutput(8));
		turnOff.reset(new DigitalOutput(9));
		SetFlashlight(false);
}

void Flashlight::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	//SetDefaultCommand(new DriveFlashlight());
}

void Flashlight::SetFlashlight(bool on) {
	//if (this->on != on) {
		this->on = on;
		//SmartDashboard::PutBoolean("LIGHT", light->Get() == Relay::kForward || light->Get() == Relay::Value::kOn);
		//light->Set(this->on ? Relay::Value::kForward : Relay::Value::kReverse);
		SmartDashboard::PutBoolean("LIGHT ON", light->Get());

		if(on)
			turnOn->Pulse(1);
		else
			turnOff->Pulse(1);
	//}
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
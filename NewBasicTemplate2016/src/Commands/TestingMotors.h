#ifndef TestingMotors_H
#define TestingMotors_H

#include "../CommandBase.h"
#include "WPILib.h"

class TestingMotors: public CommandBase
{
private:
	//  std::unique_ptr<Preferences> preferences;

	int talonMotorID,
		victorMotorID;

	bool invertTalon,
		 invertVictor;

	int direction;

	static constexpr double motorPower = 1;

	//std::unique_ptr<CANTalon> cantalonMotor;
	//std::unique_ptr<Victor> victorMotor;
	//  VictorSP* victorMotor;
public:
	TestingMotors(bool);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

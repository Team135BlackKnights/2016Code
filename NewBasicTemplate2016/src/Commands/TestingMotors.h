#ifndef TestingMotors_H
#define TestingMotors_H

#include "../CommandBase.h"
#include "WPILib.h"

class TestingMotors: public CommandBase
{
private:
	std::unique_ptr<Preferences> preferences;

	int talonMotorID,
		victorMotorID;

	bool invertTalon,
		 invertVictor;
public:
	TestingMotors();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

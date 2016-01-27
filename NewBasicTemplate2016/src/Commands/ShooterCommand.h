#ifndef ShooterCommand_H
#define ShooterCommand_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Subsystems/PIDLogging.h"
#include "Subsystems/LogData.h"
#include "Subsystems/Shooter.h"
#include "RobotMap.h"

class ShooterCommand: public CommandBase
{
private:

	std::unique_ptr<Timer> timer;

	int encoderVelocity;

	double timerValue;

public:
	ShooterCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

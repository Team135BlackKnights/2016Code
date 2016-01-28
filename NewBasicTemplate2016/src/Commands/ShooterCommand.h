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

	static const short int VELOCITY_LOG = 0b010;
	static constexpr double TIME = 5;

	double PValue,
		   IValue,
		   DValue;

	const int motorPort = Shooter::MOTOR_SHOOTER_RIGHT;

public:
	ShooterCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

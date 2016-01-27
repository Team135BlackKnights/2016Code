#ifndef ShooterCommand_H
#define ShooterCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class ShooterCommand: public CommandBase
{
public:
	ShooterCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

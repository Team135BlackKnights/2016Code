#ifndef ArmReset_H
#define ArmReset_H

#include "../CommandBase.h"
#include "WPILib.h"

class ArmReset: public CommandBase
{
private:
	static constexpr float power = .6f;
public:
	ArmReset();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

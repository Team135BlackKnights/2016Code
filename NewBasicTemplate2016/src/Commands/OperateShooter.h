#ifndef OperateShooter_H
#define OperateShooter_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "OI.h"

class OperateShooter: public CommandBase
{
private:
	double twoWheelShooterPower;
	int positiveOrNegative;
public:
	OperateShooter(bool);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

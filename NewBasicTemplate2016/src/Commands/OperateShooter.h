#ifndef OperateShooter_H
#define OperateShooter_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "OI.h"

class OperateShooter: public CommandBase
{
private:
	int joystickYValue;
	double collectionMotorPower;
	double twoWheelShooterPower;
public:
	OperateShooter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

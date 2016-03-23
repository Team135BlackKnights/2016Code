#ifndef AutoArmLower_H
#define AutoArmLower_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoArmLower: public CommandBase
{
private:
	bool armAuto;

	double desiredEncoderPosition,
		   currentEncoderPosition;

	static constexpr double MOTOR_POWER = 1.0D;

	static constexpr double ANGLE_TO_LOWER_ARM = 25.0D;
public:
	AutoArmLower(bool);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

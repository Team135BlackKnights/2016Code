#ifndef AutoArmLower_H
#define AutoArmLower_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoArmLower: public CommandBase
{
private:
	bool armAuto;

	double initialEncoderPosition,
		   lowerEncoderArmPosition,
		   desiredEncoderPosition,
		   currentEncoderPosition;

	static constexpr double motorPower = 0.8D;

	static constexpr double ANGLE_TO_LOWER_ARM = 35.0D;
public:
	AutoArmLower(bool);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

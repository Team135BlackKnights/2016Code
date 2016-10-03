#ifndef LiftHangFlipper_H
#define LiftHangFlipper_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class LiftHangFlipFlip: public Subsystem
{
private:
	std::unique_ptr<VictorSP> flipper;
public:
	LiftHangFlipFlip();
	void InitDefaultCommand();
	void DriveMotor(float power=.3f);
	int flipflipTop = 135;
	int flipflipBot = 90;
	bool isDeployed = false;
	static constexpr float FLIPPER_UP = -1.0f;
	static constexpr float FLIPPER_DOWN = -FLIPPER_UP;

	static const bool LIFT_HANG_FLIPPER_INVERTED = false;
};

#endif

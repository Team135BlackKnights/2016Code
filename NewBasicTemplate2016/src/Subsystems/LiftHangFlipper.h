#ifndef LiftHangFlipper_H
#define LiftHangFlipper_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class LiftHangFlipper: public Subsystem
{
private:
	std::unique_ptr<VictorSP> flipper;
public:
	LiftHangFlipper();
	void InitDefaultCommand();
	void DriveMotor(float power=.3f);

	static constexpr float FLIPPER_UP = 1.0f;
	static constexpr float FLIPPER_DOWN = -FLIPPER_UP;
};

#endif

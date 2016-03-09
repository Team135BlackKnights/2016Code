#ifndef LiftHangFlipper_H
#define LiftHangFlipper_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class LiftHangFlipper: public Subsystem
{
private:
	std::shared_ptr<VictorSP> flipper;
public:
	LiftHangFlipper();
	void InitDefaultCommand();
	void DriveMotor(float power=.3f);

	static const int FLIPPER_UP = 1;
	static const int FLIPPER_DOWN = -FLIPPER_UP;
};

#endif

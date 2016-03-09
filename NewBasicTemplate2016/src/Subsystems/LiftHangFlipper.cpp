#include "LiftHangFlipper.h"
#include "../RobotMap.h"

LiftHangFlipper::LiftHangFlipper() :
		Subsystem("LiftHangSlipper")
{
	flipper.reset(new VictorSP(MOTOR_LIFT_HANG_FLIPPER));
}

void LiftHangFlipper::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
}

void LiftHangFlipper::DriveMotor(float power)
{
	flipper->Set(power);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

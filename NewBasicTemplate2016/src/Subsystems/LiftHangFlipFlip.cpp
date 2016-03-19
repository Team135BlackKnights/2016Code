#include <Subsystems/LiftHangFlipFlip.h>
#include "../RobotMap.h"

LiftHangFlipFlip::LiftHangFlipFlip() :
		Subsystem("LiftHangFlipper")
{
	flipper.reset(new VictorSP(MOTOR_LIFT_HANG_FLIPPER));
	flipper->SetInverted(LIFT_HANG_FLIPPER_INVERTED);
}

void LiftHangFlipFlip::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
}

void LiftHangFlipFlip::DriveMotor(float power)
{
	flipper->Set(power);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

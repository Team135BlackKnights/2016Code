//#include <Commands/DriveLiftHangWinch.h>
#include <Subsystems/LiftHangWinch.h>
#include "../RobotMap.h"

LiftHangWinch::LiftHangWinch() :
		Subsystem("LiftHangWinch")
{
	winch.reset(new VictorSP(MOTOR_LIFT_HANG_LIFT));
	winch->SetInverted(LIFT_HANG_WINCH_INVERTED);

}

void LiftHangWinch::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new DriveLiftHang());
}

void LiftHangWinch::DriveMotor(float value) {
	winch.get()->Set(value);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

#ifndef LiftHang_H
#define LiftHang_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class LiftHangWinch: public Subsystem
{
private:
	std::unique_ptr<VictorSP> winch;
public:
	LiftHangWinch();
	void InitDefaultCommand();
	void DriveMotor(float power=1.0f);

	static constexpr float WINCH_UP = -1.0f;
	static constexpr float WINCH_DOWN = -WINCH_UP;

};

#endif

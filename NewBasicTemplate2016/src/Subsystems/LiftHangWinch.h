#ifndef LiftHang_H
#define LiftHang_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class LiftHangWinch: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::unique_ptr<VictorSP> winch;
public:
	LiftHangWinch();
	void InitDefaultCommand();
	void DriveMotor(float power=1.0f);

	static const int WINCH_UP = -1;
	static const int WINCH_DOWN = -WINCH_UP;

};

#endif

#ifndef DriveLiftHang_H
#define DriveLiftHang_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveLiftHangWinch: public CommandBase
{
	float power;
public:
	DriveLiftHangWinch(float power);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

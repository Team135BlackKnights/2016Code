#ifndef WinchLiftHang_H
#define WinchLiftHang_H

#include "../CommandBase.h"
#include "WPILib.h"

class WinchLiftHang: public CommandBase
{
	float power;
public:
	WinchLiftHang(float power);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

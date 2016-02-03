#ifndef DriveLiftHang_H
#define DriveLiftHang_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "LiftHang.h"
#include "OI.h"

class DriveLiftHang: public CommandBase
{
private:
	int direction;
public:
	DriveLiftHang(bool);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

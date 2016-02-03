#ifndef DriveLiftHang_H
#define DriveLiftHang_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveLiftHang: public CommandBase
{
public:
	DriveLiftHang();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

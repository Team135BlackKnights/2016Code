#ifndef DriveLiftHang_H
#define DriveLiftHang_H

#include "../CommandBase.h"
#include "WPILib.h"

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

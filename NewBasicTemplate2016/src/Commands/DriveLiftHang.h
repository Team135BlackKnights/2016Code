#ifndef DriveLiftHang_H
#define DriveLiftHang_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveLiftHang: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	DriveLiftHang();
	void InitDefaultCommand();
};

#endif

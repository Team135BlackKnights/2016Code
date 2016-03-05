#ifndef DriveLiftHang_H
#define DriveLiftHang_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveLiftHang: public CommandBase
{
private:
	//  These variables are set to values in the .cpp file

	//  Is equal to the value the slider returns from the designated joystick
	float liftPowerSlider,
	      flipperPowerSlider;

	//  Is equal to the value above multiplied by an "inverter"
	float liftPower,
		  flipperPower;
public:
	DriveLiftHang();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

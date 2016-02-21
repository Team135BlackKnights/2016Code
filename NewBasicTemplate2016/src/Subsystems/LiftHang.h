#ifndef LiftHang_H
#define LiftHang_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class LiftHang: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::unique_ptr<CANTalon> liftMotor; //NEEDS TO BE A CANTALON
	std::unique_ptr<VictorSP> flipperMotor;


public:
	LiftHang();
	void InitDefaultCommand();
	void DriveLiftMotor(float);
	void DriveFlipperMotor(float);

	static const int LIFT_UP = 1;
	static const int LIFT_DOWN = -LIFT_UP;

	static const int FLIPPER_UP = 1;
	static const int FLIPPER_DOWN = -FLIPPER_UP;
};

#endif

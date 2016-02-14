#ifndef DriveTrainTurnPID_H
#define DriveTrainTurnPID_H

#include "WPILib.h"
#include "DriveTrain.h"

class DriveTrainTurnPID: public PIDSource, public PIDOutput
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	DriveTrain* driveTrain;
	Servo* servo;
public:
	DriveTrainTurnPID(DriveTrain* driveTrain, Servo* servo);
	virtual ~DriveTrainTurnPID();

	double PIDGet();
	void PIDWrite(float output);
};

#endif

#ifndef DriveTrainTurnPID_H
#define DriveTrainTurnPID_H

#include "WPILib.h"
#include "CommandBase.h"

class DriveTrainTurnPID: public PIDSource, public PIDOutput
{
private:
	DriveTrain* driveTrain;
	Servo* servo;
public:
	DriveTrainTurnPID(Servo* servo);
	virtual ~DriveTrainTurnPID();

	double PIDGet();
	void PIDWrite(float output);
};

#endif

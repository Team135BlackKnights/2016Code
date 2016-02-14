#include "DriveTrainTurnPID.h"
#include "../RobotMap.h"

DriveTrainTurnPID::DriveTrainTurnPID(DriveTrain* driveTrain, Servo* servo)
{
	this->driveTrain = driveTrain;
	this->servo = servo;
}

DriveTrainTurnPID::~DriveTrainTurnPID()
{

}

double DriveTrainTurnPID::PIDGet()
{
	return (double) servo->Get();
}

void DriveTrainTurnPID::PIDWrite(float output)
{
	driveTrain->RotateTank(output);
}

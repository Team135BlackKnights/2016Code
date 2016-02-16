#include "DriveTrainTurnPID.h"
#include "../RobotMap.h"

DriveTrainTurnPID::DriveTrainTurnPID(Servo* servo)
{
	this->driveTrain = CommandBase::driveTrain.get();
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

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
	return (double) CommandBase::cam.get()->xDistanceToCenter();
}

void DriveTrainTurnPID::PIDWrite(float output)
{
	std::cout << "output: " << output <<std::endl;
	driveTrain->RotateTank(output);
}

#include "Autonomous.h"


bool IsDone = true;

Autonomous::Autonomous(int defenseNum)
{
	//AddSequential(new RobotDrive());
	switch(defenseNum){
			case "1" : // Cheval de Frise
				//AddSequential(new Manipulator(1));
				//AddSequential(new RobotDrive());
				break;
			case "2" : // Portcullis
				//AddSequential(new Manipulator(2));
				//AddSequential(new RobotDrive());
				break;
			case "3" : // Sally Port
				//AddSequential(new Manipulator(3));
				//AddSequential(new RobotDrive());
				break;
			case "4" : // Drawbridge
				//AddSequential(new Manipulator(4));
				//AddSequential(new RobotDrive());
					break;
			case "5" : // Other
				//AddSequential(new RobotDrive());
				break;

	IsDone = true;
	}

}

// Make this return true when this Command no longer needs to run execute()
bool Autonomous::IsFinished()
{
	if(IsDone == true)
		return true;
	else
		return false;
}

// Called once after isFinished returns true
void Autonomous::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Autonomous::Interrupted()
{
	this->End();
}

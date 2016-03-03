#include "GetRobotOverDefenseIntoPosition.h"
#include "RunningOverDefense.h"
#include "DriveDistance.h"
#include "TurnRobotAngle.h"


GetRobotOverDefenseIntoPosition::GetRobotOverDefenseIntoPosition(AnalogSensors::DEFENSE_METHOD typeOfDefense, int defensePosition)
{
	AddSequential(new DriveDistance(DISTANCE_NEED_TO_TRAVEL));
	AddSequential(new RunningOverDefense(typeOfDefense));

	if (defensePosition == 1) {
		AddSequential(new DriveDistance(120));
	}
	else if (defensePosition == 2) {
		AddSequential(new DriveDistance(145));
	}
	else if (defensePosition == 3) {
		AddSequential(new DriveDistance(80));
		AddSequential(new TurnRobotAngle(90,DriveTrain::RIGHT));
		AddSequential(new DriveDistance(44));
		AddSequential(new TurnRobotAngle(90, DriveTrain::LEFT));
	}
	else if (defensePosition == 4) {
		AddSequential(new DriveDistance(85));
	}
	else if (defensePosition == 5) {
		AddSequential(new DriveDistance(140));
	}

	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}

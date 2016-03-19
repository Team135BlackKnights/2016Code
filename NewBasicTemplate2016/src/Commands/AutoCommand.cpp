#include <Commands/DriveDistanceAndLowerArm.h>
#include "AutoCommand.h"
#include "DriveDistance.h"
#include "../CommandBase.h"
#include "TurnRobotAngle.h"

AutoCommand::AutoCommand(bool lowBar, int defensePosition, bool fastDefense)
{
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

	AddSequential(new DriveDistanceAndLowerArm(lowBar));

	if (fastDefense) {
		motorSpeed = .625f;
	}
	else {
		motorSpeed = .55f;
	}

	AddSequential(new DriveDistance(distanceToTravelOverDefense, motorSpeed, true));
	AddSequential(new DriveDistance(55.135f, .45f, false));

	AddSequential(new TurnRobotAngle(180.0f, RIGHT));

	if (defensePosition == 1) {
		AddSequential(new DriveDistance(38));
		AddSequential(new TurnRobotAngle(40, RIGHT));
	}

	else if (defensePosition == 2) {
		AddSequential(new DriveDistance(40));
		AddSequential(new TurnRobotAngle(35, RIGHT));
	}

	else if (defensePosition == 3) {
		AddSequential(new TurnRobotAngle(10, RIGHT));
	}

	else if (defensePosition == 4) {
		AddSequential(new DriveDistance(10, LEFT));
	}

	else if (defensePosition == 5) {
		AddSequential(new TurnRobotAngle(60, LEFT));
		AddSequential(new DriveDistance(58));
		AddSequential(new TurnRobotAngle(60, RIGHT));
	}

}

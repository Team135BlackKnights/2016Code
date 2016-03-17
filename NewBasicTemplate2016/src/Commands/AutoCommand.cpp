#include "AutoCommand.h"
#include "DriveDistance.h"
#include "../CommandBase.h"
#include "DriveToDefenseAndLowerArm.h"
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

	AddSequential(new DriveToDefenseAndLowerArm(lowBar));

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
		AddSequential(new DriveDistance(65));
	}

	else if (defensePosition == 2) {
		AddSequential(new DriveDistance(85));
	}

	else if (defensePosition == 3) {
		AddSequential(new TurnRobotAngle(45.0f, RIGHT));
		AddSequential(new DriveDistance(71));
		AddSequential(new TurnRobotAngle(45.0f, LEFT));
	}

	else if (defensePosition == 4) {
		AddSequential(new DriveDistance(10));
	}

	else if (defensePosition == 5) {
		AddSequential(new DriveDistance(65));
	}

}

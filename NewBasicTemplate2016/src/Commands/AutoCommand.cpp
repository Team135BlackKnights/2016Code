#include "AutoCommand.h"
#include "AutomationOfArm.h"
#include "DriveDistance.h"
#include "TurnRobotAngle.h"
#include "../CommandBase.h"

AutoCommand::AutoCommand(int typeOfDefense, int defensePosition)
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

	//AddParallel(new AutomationOfArm(30.0D));
	AddSequential(new DriveDistance(DRIVE_DISTANCE_TO_RAMP, 0.45f, ZERO));

	//AddSequential(new DriveDistance(rampartsDistance, 0.5f));

	if (typeOfDefense == DriveTrain::LOW_BAR) {
		AddSequential(new DriveDistance(lowBarDistance));
	}
	else if (typeOfDefense == DriveTrain::MOAT) {
		AddSequential(new DriveDistance(moatDistance, .6f));
	}
	else if (typeOfDefense == DriveTrain::RAMPARTS) {
		AddSequential(new DriveDistance(rampartsDistance, .55f));
	}
	else if (typeOfDefense == DriveTrain::ROCK_WALL) {
		AddSequential(new DriveDistance(rockWallDistance));
	}
	else if (typeOfDefense == DriveTrain::ROUGH_TERRAIN) {
		AddSequential(new DriveDistance(roughTerrainDistance, .5f));
	}

	AddSequential(new DriveDistance(16.135f, .65125135135135f));

	if (defensePosition == 1) {
		AddSequential(new DriveDistance(65));
	}
	else if (defensePosition == 2) {
		AddSequential(new DriveDistance(85));
	}
	else if (defensePosition == 3) {
		AddSequential(new TurnRobotAngle(45.0f, RIGHT, 0.4f));
		AddSequential(new DriveDistance(71));
		AddSequential(new TurnRobotAngle(45.0f, LEFT, 0.4f));
	}
	else if (defensePosition == 4) {
		AddSequential(new DriveDistance(10));
	}
	else if (defensePosition == 5) {
		AddSequential(new DriveDistance(65));
	}

}

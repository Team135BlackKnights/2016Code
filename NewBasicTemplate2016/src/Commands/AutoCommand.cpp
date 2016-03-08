#include "AutoCommand.h"

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

	AddSequential(new DriveDistance(DRIVE_DISTANCE_TO_RAMP, MOTOR_POWER_TO_RAMP, ZERO));

	//AddSequential(new DriveDistance(rampartsDistance, 0.5f));

	if (typeOfDefense == DriveTrain::LOW_BAR) {
		AddSequential(new DriveDistance(lowBarDistance));
	}
	else if (typeOfDefense == DriveTrain::MOAT) {
		AddSequential(new DriveDistance(moatDistance));
	}
	else if (typeOfDefense == DriveTrain::RAMPARTS) {
		AddSequential(new DriveDistance(rampartsDistance));
	}
	else if (typeOfDefense == DriveTrain::ROCK_WALL) {
		AddSequential(new DriveDistance(rockWallDistance));
	}
	else if (typeOfDefense == DriveTrain::ROUGH_TERRAIN) {
		AddSequential(new DriveDistance(roughTerrainDistance));
	}

	/*if (defensePosition == 1) {
		AddSequential(new DriveDistance(120));
	}
	else if (defensePosition == 2) {
		AddSequential(new DriveDistance(145));
	}
	else if (defensePosition == 3) {
		AddSequential(new DriveDistance(80));
		AddSequential(new TurnRobotAngle(90, RIGHT, 0.4f));
		AddSequential(new DriveDistance(44));
		AddSequential(new TurnRobotAngle(90, LEFT, 0.4f));
	}
	else if (defensePosition == 4) {
		AddSequential(new DriveDistance(85));
	}
	else if (defensePosition == 5) {
		AddSequential(new DriveDistance(140));
	} */

}
